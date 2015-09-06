#
# pxlib and pxview
#
# Originally written by Uwe Steinmann (see pxlib.sourceforge.net)
#

AC_INIT(pxlibview, [0.5], [http://github.com/jsquyres/pxlib-and-pxview])
AC_CONFIG_SRCDIR(pxlib/src/paradox.c)
AM_INIT_AUTOMAKE([foreign dist-bzip2 no-define 1.11])

AM_SILENT_RULES([yes])

AC_CONFIG_MACRO_DIR([m4])

AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)

dnl build date
PXLIB_BUILD_DATE=`date '+%Y-%m-%d'`
AC_DEFINE_UNQUOTED(PXLIB_BUILD_DATE,"$PXLIB_BUILD_DATE",[pxlib build date])
AC_SUBST(PXLIB_BUILD_DATE)

dnl the following sets the soname version
PXLIB_MAJOR_VERSION=0
PXLIB_MINOR_VERSION=6
PXLIB_MICRO_VERSION=3
PXLIB_VERSION=$PXLIB_MAJOR_VERSION.$PXLIB_MINOR_VERSION.$PXLIB_MICRO_VERSION
PXLIB_VERSION_INFO=`expr $PXLIB_MAJOR_VERSION + $PXLIB_MINOR_VERSION`:$PXLIB_MICRO_VERSION:$PXLIB_MINOR_VERSION

AC_SUBST(PXLIB_MAJOR_VERSION)
AC_SUBST(PXLIB_MINOR_VERSION)
AC_SUBST(PXLIB_MICRO_VERSION)
AC_SUBST(PXLIB_VERSION)
AC_SUBST(PXLIB_VERSION_INFO)

AC_DEFINE_UNQUOTED(PXLIB_MAJOR_VERSION, [$PXLIB_MAJOR_VERSION], PXLIB_MAJOR_VERSION)
AC_DEFINE_UNQUOTED(PXLIB_MINOR_VERSION, [$PXLIB_MINOR_VERSION], PXLIB_MINOR_VERSION)
AC_DEFINE_UNQUOTED(PXLIB_MICRO_VERSION, [$PXLIB_MICRO_VERSION], PXLIB_MICRO_VERSION)

PXVIEW_MAJOR_VERSION=0
PXVIEW_MINOR_VERSION=2
PXVIEW_MICRO_VERSION=5
PXVIEW_VERSION=$PXVIEW_MAJOR_VERSION.$PXVIEW_MINOR_VERSION.$PXVIEW_MICRO_VERSION
PXVIEW_VERSION_INFO=`expr $PXVIEW_MAJOR_VERSION + $PXVIEW_MINOR_VERSION`:$PXVIEW_MICRO_VERSION:$PXVIEW_MINOR_VERSION

AC_SUBST(PXVIEW_MAJOR_VERSION)
AC_SUBST(PXVIEW_MINOR_VERSION)
AC_SUBST(PXVIEW_MICRO_VERSION)
AC_SUBST(PXVIEW_VERSION)
AC_SUBST(PXVIEW_VERSION_INFO)
AC_DEFINE_UNQUOTED(PXVIEW_VERSION, ["$PXVIEW_VERSION"], [Version of pxview])

dnl Checks for programs.
AC_PROG_CC_C99

AM_PROG_LIBTOOL

dnl JMS i18n is currently broken... :-(
dnl Add the languages which your application supports here.
dnl ALL_LINGUAS="de es fr"
dnl AC_SUBST(ALL_LINGUAS)
dnl AM_GLIB_GNU_GETTEXT
dnl GETTEXT_PACKAGE=pxlib
dnl AC_SUBST(GETTEXT_PACKAGE)
dnl AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", GETTEXT_PACKAGE)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_BIGENDIAN
AC_STRUCT_TM

dnl Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS(fcntl.h unistd.h ctype.h dirent.h errno.h malloc.h)
AC_CHECK_HEADERS(stdbool.h stdarg.h sys/stat.h sys/types.h time.h)
AC_CHECK_HEADERS(ieeefp.h nan.h math.h fp_class.h float.h)
AC_CHECK_HEADERS(stdlib.h sys/socket.h netinet/in.h arpa/inet.h)
AC_CHECK_HEADERS(netdb.h sys/time.h sys/select.h sys/mman.h)
AC_CHECK_HEADERS(libintl.h)

dnl Checks for library functions.
AC_FUNC_STRFTIME
AC_CHECK_FUNCS(strdup strndup strerror snprintf)
AC_CHECK_FUNCS(finite isnand fp_class class fpclass)
AC_CHECK_FUNCS(strftime localtime)

dnl Checks for inet libraries:
AC_CHECK_FUNC(gethostent, , AC_CHECK_LIB(nsl, gethostent))
AC_CHECK_FUNC(setsockopt, , AC_CHECK_LIB(socket, setsockopt))
AC_CHECK_FUNC(connect, , AC_CHECK_LIB(inet, connect))

dnl
dnl Extra flags
dnl

AC_ARG_WITH(memory-debug,
    AC_HELP_STRING([--with-memory-debug],
                   [Adds extra code for memory debugging]))

if test "x$with_memory_debug" = "xyes" ; then
	AC_DEFINE(MEMORY_DEBUGGING, 1, [Define if you want memory debugging.])
fi

dnl
dnl Debug
dnl

AC_ARG_WITH(debug,
    AC_HELP_STRING([--with-debug],
                   [Add the debugging module (on)]))

if test "$with_debug" = "no" ; then
    echo Disabling DEBUG support
    WITH_DEBUG=0
    DEBUG_OBJ=
else    
    WITH_DEBUG=1
    DEBUG_OBJ=debugPX.o
fi
AC_SUBST(WITH_DEBUG)
AC_DEFINE_UNQUOTED(WITH_DEBUG, [$WITH_DEBUG], [Do we want debug or not?])
AC_SUBST(DEBUG_OBJ)

dnl
dnl iconv / recode
dnl

PX_HAVE_ICONV=0
PX_HAVE_RECODE=0

m4_ifdef([AM_ICONV_LINK], [AM_ICONV_LINK])
if test "$am_cv_func_iconv" != "yes" ; then
	AC_ARG_WITH(recode,
            AC_HELP_STRING([--with-recode=DIR],
                           [Path to recode library]))
	if test -r ${with_recode}/include/recode.h ; then
		RECODE_LIBDIR=-L${with_recode}/lib
		RECODE_INCLUDEDIR=-I${with_recode}/include
	fi

	AC_CHECK_LIB(recode, recode_new_outer,
		[
		RECODE_LIBDIR="$RECODE_LIBDIR -lrecode";
		RECODE_LIBS=-lrecode;
		PX_HAVE_RECODE=1;
		AC_DEFINE(HAVE_RECODE, 1, [Define if you have the recode library.])
		],[
		AC_MSG_RESULT([librecode not found])
		], "$RECODE_LIBDIR")

else
	PX_HAVE_ICONV=1
	AC_MSG_CHECKING([for recode])
	AC_MSG_RESULT([not needed (using iconv)])
fi

AC_SUBST(RECODE_LIBDIR)
AC_SUBST(RECODE_LIBS)
AC_SUBST(RECODE_INCLUDEDIR)

AC_SUBST(PX_HAVE_RECODE)
AC_DEFINE_UNQUOTED(PX_USE_RECODE, [$PX_HAVE_RECODE], [Do we have recode or not?])
AC_SUBST(PX_HAVE_ICONV)
AC_DEFINE_UNQUOTED(PX_USE_ICONV, [$PX_HAVE_ICONV], [Do we have iconv or not?])

dnl
dnl GSF
dnl

PX_HAVE_GSF=0

AC_ARG_WITH(gsf,
	AC_HELP_STRING([--with-gsf=DIR],
                       [Path to gsf library]))

if test "x$with_gsf" = xno; then
    AC_MSG_CHECKING([for gsf])
    AC_MSG_RESULT([disabled by user])
    PX_HAVE_GSF=0
else
    if test -r ${with_gsf}/include/libgsf-1/gsf/gsf-input.h ; then
        GSF_LIBDIR=-L${with_gsf}/lib
        GSF_INCLUDEDIR="-I${with_gsf}/include/libgsf-1 -I${with_gsf}/include/glib-2.0 -I${with_gsf}/lib/glib-2.0/include"
        try_gsf=true
    else
        if test -r /usr/include/libgsf-1/gsf/gsf-input.h ; then
            GSF_LIBDIR=-L/usr
            GSF_INCLUDEDIR="-I/usr/include/libgsf-1 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include"
            try_gsf=true
        else
            try_gsf=false
        fi
    fi

    if test "$try_gsf" = "true"; then
        AC_CHECK_LIB(gsf-1, gsf_input_read,
            [GSF_LIBDIR="$GSF_LIBDIR -lgsf-1"],
            [AC_MSG_RESULT([libgsf-1 not found])],
	    ["$GSF_LIBDIR"])

        GSF_LIBS=-lgsf-1
        AC_DEFINE(HAVE_GSF, 1, [Define if you have the gsf library.])
        PX_HAVE_GSF=1
    fi
fi

AC_SUBST(GSF_LIBDIR)
AC_SUBST(GSF_LIBS)
AC_SUBST(GSF_INCLUDEDIR)

AC_SUBST(PX_HAVE_GSF)
AC_DEFINE_UNQUOTED(PX_HAVE_GSF, [$PX_HAVE_GSF], [Do we have GSF or not?])

dnl
dnl Docbook
dnl

AC_CHECK_PROG(DOC_TO_MAN, docbook-to-man, docbook-to-man)
if test "x$DOC_TO_MAN" = "x"; then
	BUILD_DOCS=0
	AC_MSG_RESULT([docbook-to-man could not be found. I will not build man pages!])
else
	BUILD_DOCS=1
fi
AM_CONDITIONAL(BUILD_DOCS, [test "$BUILD_DOCS" = "1"])
AC_SUBST(DOC_TO_MAN)

dnl
dnl Party on
dnl

AC_CONFIG_HEADERS([
    pxlib/include/pxversion.h
    pxlib/include/paradox.h
    pxlib/include/paradox-gsf.h
])

AC_CONFIG_FILES([
    Makefile

    pxlib/Makefile
    pxlib/pxlib.pc
    pxlib/include/Makefile
    pxlib/src/Makefile
    pxlib/doc/Makefile

    pxview/Makefile
    pxview/src/Makefile
    pxview/doc/Makefile
])

dnl JMS i18n stuff is still broken... :-(
dnl pxlib/po/Makefile.in
dnl pxview/po/Makefile.in

AC_OUTPUT

cat <<EOF
Configuration:
  Prefix:     $prefix
EOF
if test "$PX_HAVE_ICONV" = "1" ; then
    echo "  Recoding: using iconv";
else
    if test "$PX_HAVE_RECODE" = "1" ; then
        echo "  Recoding: using recode";
    else
        echo "  Recoding: no support";
    fi
fi
echo ""
