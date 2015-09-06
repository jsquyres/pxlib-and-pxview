bin_PROGRAMS = pxview

pxview_SOURCES = main.c
pxview_CPPFLAGS = \
        $(GSF_INCLUDEDIR) \
        $(SQLITE_INCLUDEDIR) \
        -I@top_srcdir@/pxlib/include \
        -I@top_srcdir@/pxlib/src \
        -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"
pxview_LDADD = \
        $(top_builddir)/pxlib/src/libpx.la \
        $(GSF_LIBDIR) \
        $(GSF_LIBS) \
        $(SQLITE_LIBDIR) \
        $(SQLITE_LIBS) \
        $(INTLLIBS)
