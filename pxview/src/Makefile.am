## Process this file with automake to produce Makefile.in

INCLUDES = $(PX_INCLUDEDIR) $(GSF_INCLUDEDIR) $(SQLITE_INCLUDEDIR) -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"

bin_PROGRAMS = pxview

pxview_SOURCES = main.c

pxview_LDADD = $(PX_LIBDIR) $(PX_LIBS) $(GSF_LIBDIR) $(GSF_LIBS) $(SQLITE_LIBDIR) $(SQLITE_LIBS)
