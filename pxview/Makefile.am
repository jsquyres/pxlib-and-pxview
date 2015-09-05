ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src po doc

spec = $(PACKAGE).spec

EXTRA_DIST = \
        COPYING \
        INSTALL \
        intltool-extract.in \
        intltool-merge.in \
        intltool-update.in \
        $(spec) $(spec).in \
        autogen.sh

rpm: $(distdir).tar.gz
	rpm -ta $(distdir).tar.gz
