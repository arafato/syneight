dnl @synopsis AX_PATH_BOOST([MINIMUM-VERSION], [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
dnl
dnl AX_PATH_BOOST checks if the C++ library Boost (http://www.boost.org) is
dnl available and is working.
dnl
dnl If the MINIMUM-VERSION argument is passed, AX_PATH_BOOST will cause an
dnl error if the installed Boost version doesn't meet the requirement.
dnl MINIMUM-VERSION must be given in the format which is used in the
dnl boost/version.hpp file, e.g. 103100 stands for version 1.31.0.
dnl   MINIMUM-VERSION % 100 is the sub-minor version
dnl   MINIMUM-VERSION / 100 % 1000 is the minor version
dnl   MINIMUM-VERSION / 100000 is the major version
dnl
dnl If Boost is found ACTION-IF-FOUND is executed, otherwise
dnl ACTION-IF-NOT-FOUND is executed, if given.
dnl
dnl AX_PATH_BOOST provides a --with-boost-prefix=PREFIX configure option. The
dnl default value for PREFIX is 'auto', which means we try to guess where Boost
dnl resides (trying all the usual system include directories).
dnl If PREFIX is set, we only try to find Boost in the directory PREFIX.
dnl
dnl AX_PATH_BOOST also provides a --disable-boost-test configure option. Using
dnl this, you can disable the check for Boost. Note that no BOOST_FOUND,
dnl BOOST_PREFIX or BOOST_VERSION variables will be defined in this case.
dnl 
dnl Results:
dnl   * BOOST_FOUND is 'yes' if Boost is available, 'no' otherwise.
dnl   * BOOST_PREFIX is set to the prefix where Boost was found. If no working
dnl     Boost installation is found, BOOST_PREFIX is empty.
dnl   * BOOST_VERSION contains the version number of Boost, if Boost was found.
dnl     The version format is the same as in boost/version.hpp, e.g.
dnl     103100 stands for version 1.31.0.
dnl
dnl Example:
dnl   If Boost 1.31.0 is installed in /usr/include/boost, BOOST_FOUND will be
dnl   set to 'yes', BOOST_PREFIX will be set to '/usr/include' and
dnl   BOOST_VERSION will be set to '103100'.
dnl
dnl @version 0.1
dnl
dnl @author Uwe Hermann <uwe@hermann-uwe.de>
dnl

AC_DEFUN([AX_PATH_BOOST],
[
  dnl Add a --with-boost-prefix option to configure. Using this, you can
  dnl specify an alternative installation prefix for Boost, in case it's
  dnl not installed in a standard include directory.
  AC_ARG_WITH([boost-prefix],
              AC_HELP_STRING([--with-boost-prefix=PREFIX],
                             [Prefix where Boost is installed (optional)]),
              [ax_cv_boost_prefix="$withval"], [ax_cv_boost_prefix=""])

  dnl Add a --disable-boost-test option to configure. Using this, you can
  dnl disable the check for Boost, if you want to.
  AC_ARG_ENABLE([boost-test],
                AC_HELP_STRING([--disable-boost-test],
                               [Do not try to compile and run a test Boost program]),
                [ax_cv_enable_boost_test="$enableval"],
                [ax_cv_enable_boost_test=yes])

  dnl Only continue if the user didn't specify --disable-boost-test.
  if test "x$ax_cv_enable_boost_test" != xno ; then

  dnl Either use the user-specified Boost installation prefix, or try some
  dnl likely installation prefixes.
  if test "x$ax_cv_boost_prefix" != x; then
    all_boost_prefixes="$ax_cv_boost_prefix"
  else
    all_boost_prefixes="/usr/include /usr/local/include"
  fi

  dnl In the beginning we assume Boost isn't installed.
  BOOST_FOUND=no
  BOOST_PREFIX=
  BOOST_VERSION=

  dnl Print that we're now checking for Boost.
  m4_if([$1], [], [
    dnl No version check is needed.
    AC_MSG_CHECKING([for Boost])
  ], [
    dnl A version check is needed.
    AC_MSG_CHECKING([for Boost version >= $1])
  ])

  dnl Push the current language to a stack and use C++ from now on.
  AC_LANG_PUSH(C++)

  dnl Try to find Boost in each of the given installation prefixes.
  for boost_prefix in $all_boost_prefixes
  do
    dnl Don't continue, if we have already found a working Boost installation.
    if test "x$BOOST_FOUND" != xyes; then
      dnl Try to compile a simple program using Boost's multi_array. If that
      dnl succeeds we asssume Boost is available and works properly.

      ax_save_CFLAGS="$CFLAGS"
      CFLAGS="$CFLAGS -I$boost_prefix"
      AC_COMPILE_IFELSE([dnl
        AC_LANG_SOURCE([[#include <boost/scoped_ptr.hpp>]],
                       [[::boost::scoped_ptr<int> pointer;]])],
        [BOOST_FOUND=yes; BOOST_PREFIX=$boost_prefix],
        [BOOST_FOUND=no]
      )
      CFLAGS="$ax_save_CFLAGS"

      dnl If MINIMUM-VERSION is given and we have found a Boost installation,
      dnl check if it fulfills the version requirement.
      if test "x$1" != x && test "x$BOOST_FOUND" = xyes; then
        dnl Get the Boost version.
        BOOST_VERSION=`grep "^#define BOOST_VERSION " $BOOST_PREFIX/boost/version.hpp 2>/dev/null | sed 's/[^0-9]//g'`

        dnl If the installed Boost is too old, check the next prefix.
        dnl The version numbers are prefixed with 9, because otherwise they
        dnl might be interpreted as octal values.
        if test 9$BOOST_VERSION -le 9$1; then
          BOOST_FOUND=no
          BOOST_PREFIX=
          BOOST_VERSION=
        fi
      fi

    fi
  done

  dnl Pop the previously saved language from the stack.
  AC_LANG_POP(C++)

  dnl Print whether we have found a working Boost installation.
  if test "x$BOOST_FOUND" = xyes; then
    dnl Yes, we found a working Boost installation.
    AC_MSG_RESULT([$BOOST_FOUND, version $BOOST_VERSION in $BOOST_PREFIX])

    dnl Execute ACTION-IF-FOUND.
    m4_if([$2], , :, [$2])
  else
    dnl Sorry, no working Boost installation found.
    AC_MSG_RESULT([$BOOST_FOUND])

    dnl Execute ACTION-IF-NOT-FOUND.
    m4_if([$3], , :, [$3])
  fi

  dnl Make BOOST_FOUND, BOOST_PREFIX and BOOST_VERSION known to autoconf.
  AC_SUBST([BOOST_FOUND])
  AC_SUBST([BOOST_PREFIX])
  AC_SUBST([BOOST_VERSION])

  dnl ...
  fi
])

