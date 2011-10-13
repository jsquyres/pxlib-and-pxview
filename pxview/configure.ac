dnl Process this file with autoconf to produce a configure script.
AC_INIT(pxview, 0.2.5p1, http://sourceforge.net/pxlib)
AC_CONFIG_SRCDIR(src/main.c)
AM_INIT_AUTOMAKE([foreign dist-bzip2 no-define 1.11])

AM_SILENT_RULES([yes])

AC_CONFIG_SUBDIRS([m4])
AC_CONFIG_MACRO_DIRS([m4])

AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)

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
AC_DEFINE_UNQUOTED(PXVIEW_VERSION, "$PXVIEW_VERSION", [Version of pxview])

dnl Checks for programs.
AC_PROG_CC

dnl Check for pxlib
AC_ARG_WITH(pxlib, AC_HELP_STRING([--with-pxlib=DIR],
                                  [Path to paradox library (/usr)]))
if test "$with_pxlib" != "yes" -a "$with_pxlib" != "no" -a -n "$with_pxlib"; then
	PX_LIBDIR=-L${with_pxlib}/lib
	PX_INCLUDEDIR=-I${with_pxlib}/include 
        CPPFLAGS="$PX_INCLUDEDIR $CPPFLAGS"
        LDFLAGS="$PX_LIBDIR $LDFLAGS"
fi

AC_CHECK_HEADER([paradox.h], [], [AC_MSG_ERROR([Cannot find paradox.h])])
dnl libpx may require libiconv.  So check to see if we have it (which
dnl will automatically add it to $LIBS if we do).
AC_CHECK_LIB([iconv], [iconv_open])
AC_CHECK_LIB([px], [PX_timestamp2string], [], 
  [AC_MSG_ERROR([libpx not found. You will need at least libpx 0.4.4])])

PX_LIBS=-lpx

dnl Add the languages which your application supports here.
ALL_LINGUAS="de"
AM_GLIB_GNU_GETTEXT
GETTEXT_PACKAGE=pxview
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", GETTEXT_PACKAGE)

AM_PROG_LIBTOOL

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_BIGENDIAN
AC_STRUCT_TM

dnl Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS(fcntl.h unistd.h ctype.h dirent.h errno.h malloc.h)
AC_CHECK_HEADERS(stdarg.h sys/stat.h sys/types.h time.h)
AC_CHECK_HEADERS(stdlib.h sys/socket.h netinet/in.h arpa/inet.h)
AC_CHECK_HEADERS(netdb.h sys/time.h sys/select.h sys/mman.h)
AC_CHECK_HEADERS(libintl.h)

dnl Checks for library functions.
AC_FUNC_STRFTIME
AC_CHECK_FUNCS(strdup strndup strerror snprintf)
AC_CHECK_FUNCS(finite isnand fp_class class fpclass)
AC_CHECK_FUNCS(strftime localtime)

dnl JMS This should really be cleaned up:
dnl - use $with_gsf
dnl - directly add to CPPFLAGS, LDFLAGS, and LIBS
dnl - delete all refs to GSF_LIBDIR, GSF_INCLUDEDIR (and in src/Makefile.am)
AC_ARG_WITH(gsf, [  --with-gsf=DIR          Path to gsf library (/usr)],
if test "x$withval" = xno; then
	AC_MSG_RESULT("disable by user")
else
	if test -r ${withval}/include/libgsf-1/gsf/gsf-input.h ; then
		GSF_LIBDIR=-L${withval}/lib
		GSF_INCLUDEDIR="-I${withval}/include/libgsf-1 -I${withval}/include/glib-2.0 -I${withval}/lib/glib-2.0/include"
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
			GSF_LIBDIR="$GSF_LIBDIR -lgsf-1",
			AC_MSG_RESULT([libgsf-1 not found]),
			"$GSF_LIBDIR")

		GSF_LIBS=-lgsf-1
		AC_DEFINE(HAVE_GSF, 1, [Define if you have the gsf library.])
	fi
fi
)

dnl JMS This should really be cleaned up:
dnl - use $with_sqlite
dnl - directly add to CPPFLAGS, LDFLAGS, and LIBS
dnl - delete all refs to SQLITE_LIBDIR, SQLITE_INCLUDEDIR (and in src/Makefile.am)
AC_ARG_WITH(sqlite, [  --with-sqlite=DIR       Path to sqlite library (/usr)],
if test "x$withval" = xno; then
	AC_MSG_RESULT("disable by user")
else
	if test -r ${withval}/include/sqlite.h ; then
		SQLITE_LIBDIR=-L${withval}/lib
		SQLITE_INCLUDEDIR="-I${withval}/include"
		try_sqlite=true
	else
		if test -r /usr/include/sqlite.h ; then
			SQLITE_LIBDIR=-L/usr
			SQLITE_INCLUDEDIR="-I/usr/include"
			try_sqlite=true
		else
			AC_MSG_ERROR(header file for sqlite not found)
			try_sqlite=false
		fi
	fi

	if test "$try_sqlite" = "true"; then
		AC_CHECK_LIB(sqlite, sqlite_open,
			SQLITE_LIBDIR="$SQLITE_LIBDIR -lsqlite",
			AC_MSG_RESULT([libsqlite not found]),
			"$SQLITE_LIBDIR")

		SQLITE_LIBS=-lsqlite
		AC_DEFINE(HAVE_SQLITE, 1, [Define if you have the sqlite library.])
	fi
fi
)

AC_CHECK_PROG(DOC_TO_MAN, docbook-to-man, docbook-to-man)
if test ! "$DOC_TO_MAN" ; then
        BUILD_DOCS=0
	AC_MSG_RESULT([docbook-to-man could not be found. I will not build man pages!])
else
        BUILD_DOCS=1
fi
AM_CONDITIONAL(BUILD_DOCS, [test "$BUILD_DOCS" = "1"])

dnl
dnl Extra flags
dnl

AC_ARG_WITH(memory-debug, [  --with-memory-debug     Adds extra code for memory debugging])
if test "x$with_memory_debug" = "xyes" ; then
	AC_DEFINE(MEMORY_DEBUGGING, 1, [Define if you want memory debugging.])
fi

AC_SUBST(GSF_LIBDIR)
AC_SUBST(GSF_LIBS)
AC_SUBST(GSF_INCLUDEDIR)

AC_SUBST(SQLITE_LIBDIR)
AC_SUBST(SQLITE_LIBS)
AC_SUBST(SQLITE_INCLUDEDIR)

AC_SUBST(DOC_TO_MAN)

dnl AC_DEFINE_UNQUOTED(PXVIEW_MAJOR_VERSION, "$PXVIEW_MAJOR_VERSION", PXVIEW_MAJOR_VERSION)
dnl AC_DEFINE_UNQUOTED(PXVIEW_MINOR_VERSION, "$PXVIEW_MINOR_VERSION", PXVIEW_MINOR_VERSION)
dnl AC_DEFINE_UNQUOTED(PXVIEW_MICRO_VERSION, "$PXVIEW_MICRO_VERSION", PXVIEW_MICRO_VERSION)

AC_CONFIG_FILES([
pxview.spec
Makefile
src/Makefile
doc/Makefile
po/Makefile.in
])
AC_OUTPUT

cat <<EOF

Configuration:
  Prefix:     ${prefix}

EOF
