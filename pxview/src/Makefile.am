## Process this file with automake to produce Makefile.in

bin_PROGRAMS = pxview

pxview_SOURCES = main.c
pxview_CPPFLAGS = \
        $(GSF_INCLUDEDIR) $(SQLITE_INCLUDEDIR) -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"
pxview_LDADD = $(GSF_LIBDIR) $(GSF_LIBS) $(SQLITE_LIBDIR) $(SQLITE_LIBS)
