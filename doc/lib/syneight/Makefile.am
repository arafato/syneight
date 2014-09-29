#------------------------------------------------------------------------------
# Syneight - A soft-realtime transaction monitor
# Copyright (C) 2003-2004 The Syneight Group
#
# TODO: License.
#------------------------------------------------------------------------------

# Get all *.tex files in the current directory.
# FIXME: This is not very portable.
SYNEIGHT_TEXFILES = $(wildcard *.tex)

# Extra files which should be included in the distribution.
EXTRA_DIST = \
$(SYNEIGHT_TEXFILES) \
paperversion.sty \
apeiron_logo.eps \
apeiron_logo.pdf

# Syneight specific Makefile targets.
docs-ps:
docs-pdf:
docs:

# Include some common Makefile targets.
include $(top_srcdir)/Makefile.common

