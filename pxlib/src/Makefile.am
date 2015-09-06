lib_LTLIBRARIES = libpx.la

libpx_la_SOURCES = \
                fileformat.h \
                px_error.h \
                px_head.h \
                px_io.h \
                px_intern.h \
                px_memory.h \
                px_misc.h \
                px_encode.h \
                px_crypt.h \
                sdncal.h \
		paradox.c \
		px_head.c \
		px_misc.c \
		px_io.c \
		px_memory.c \
		px_memprof.c \
		px_error.c \
		px_encode.c \
		px_crypt.c \
		gregor.c
libpx_la_CPPFLAGS = \
        -I@top_srcdir@/pxlib/include \
        -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\" \
        @RECODE_INCLUDEDIR@ @GSF_INCLUDEDIR@
libpx_la_LDFLAGS = -version-info @PXLIB_VERSION_INFO@
libpx_la_LIBADD = \
        -lm \
        $(RECODE_LIBS) \
        $(GSF_LIBS) \
        $(INTLLIBS)
