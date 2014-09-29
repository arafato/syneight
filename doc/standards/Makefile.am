#------------------------------------------------------------------------------
# Syneight - A soft-realtime transaction monitor
# Copyright (C) 2003-2004 The Syneight Group
#
# TODO: License.
#------------------------------------------------------------------------------

# Get all *.tex files in the current directory.
# FIXME: This is not very portable.
SYNEIGHT_TEXFILES = $(wildcard $(srcdir)/*.tex)

# Extra files which should be included in the distribution.
EXTRA_DIST = \
$(SYNEIGHT_TEXFILES)

# Files which should be removed by 'make clean'.
CLEANFILES = \
*.ps *.pdf

# Syneight specific Makefile targets.
syneight_target = standards

$(syneight_target).dvi: $(SYNEIGHT_TEXFILES) $(SYNEIGHT_TEXLIBDIR)/syneight/env.tex $(SYNEIGHT_TEXLIBDIR)/syneight/people.tex $(SYNEIGHT_TEXLIBDIR)/syneight/definedterms.tex $(SYNEIGHT_TEXLIBDIR)/syneight/abbreviations.tex

docs-api:
docs-ps: $(syneight_target).ps
docs-pdf: $(syneight_target).pdf
docs: docs-ps docs-pdf

# Include some common Makefile targets.
include $(top_srcdir)/Makefile.common

