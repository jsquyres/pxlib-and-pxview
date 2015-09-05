bin_PROGRAMS = pxview

pxview_SOURCES = main.c
pxview_CPPFLAGS = \
        -DBOGUS=111111 \
        $(GSF_INCLUDEDIR) \
        $(SQLITE_INCLUDEDIR) \
        -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"

pxview_LDADD = \
        $(GSF_LIBDIR) \
        $(GSF_LIBS) \
        $(SQLITE_LIBDIR) \
        $(SQLITE_LIBS) \
        $(INTLLIBS)
