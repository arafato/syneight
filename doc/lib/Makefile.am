#------------------------------------------------------------------------------
# Syneight - A soft-realtime transaction monitor
# Copyright (C) 2003-2004 The Syneight Group
#
# TODO: License.
#------------------------------------------------------------------------------

# Subdirectories to process.
SUBDIRS = syneight

# Syneight specific recursive Makefile targets.
SYNEIGHT_RECURSIVE_TARGETS = docs docs-ps docs-pdf

# Call the respective Makefile rule in each subdirectory listed in SUBDIRS.
$(SYNEIGHT_RECURSIVE_TARGETS):
	@subdirs='$(SUBDIRS)'; \
	target=`echo $@`; \
	for subdir in $$subdirs; do \
	echo "Making $$target in $$subdir"; \
	(cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$target) || exit 1; \
	done;

# Kill recursive targets
docs-api:

# Include some common Makefile targets.
include $(top_srcdir)/Makefile.common

