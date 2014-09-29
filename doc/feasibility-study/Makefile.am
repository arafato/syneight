#------------------------------------------------------------------------------
# Syneight - A soft-realtime transaction monitor
# Copyright (C) 2003-2004 The Syneight Group
#
# TODO: License.
#------------------------------------------------------------------------------

# Get all *.tex files in the current directory.
# FIXME: This is not very portable.
SYNEIGHT_TEXFILES = $(wildcard $(srcdir)/*.tex)

# The *.bib file used to create the bibliography of the target document.
SYNEIGHT_BIBFILE = $(srcdir)/feasibility-study.bib

# Extra files which should be included in the distribution.
EXTRA_DIST = \
$(SYNEIGHT_TEXFILES) \
$(SYNEIGHT_BIBFILE)

# Files which should be removed by 'make clean'.
CLEANFILES = \
*.ps *.pdf

# Syneight specific Makefile targets.
syneight_target = feasibility-study

$(syneight_target).dvi: $(SYNEIGHT_TEXFILES) $(SYNEIGHT_BIBFILE) $(SYNEIGHT_TEXLIBDIR)/syneight/env.tex $(SYNEIGHT_TEXLIBDIR)/syneight/definedterms.tex $(SYNEIGHT_TEXLIBDIR)/syneight/abbreviations.tex

docs-api:
docs-ps: $(syneight_target).ps
docs-pdf: $(syneight_target).pdf
docs: docs-ps docs-pdf

# Include some common Makefile targets.
include $(top_srcdir)/Makefile.common

