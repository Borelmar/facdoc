#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.



AC_PREREQ([2.69])
AC_INIT([facdoc], [0.0.1], [h4x0r@gnu.org])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_SRCDIR([src/facdoc.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects])



# Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_AWK
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX([noyywrap])



# CHECK TARGET HOST PLATFORM
dnl AC_CANONICAL_HOST is needed to access the 'host_os' variable    
AC_CANONICAL_HOST
build_linux=no
build_windows=no
build_mac=no
# Detect the target system
case "${host_os}" in
    linux*)
        build_linux=yes
        ;;
    mingw*)
        build_windows=yes
        ;;
    darwin*)
        build_mac=yes
        ;;
    *)
        AC_MSG_ERROR(["OS $host_os is not supported"])
        ;;
esac
# Pass the conditionals to automake
AM_CONDITIONAL([LINUX], [test "$build_linux" = "yes"])
AM_CONDITIONAL([WINDOWS], [test "$build_windows" = "yes"])
AM_CONDITIONAL([OSX], [test "$build_mac" = "yes"])



# Checks for libraries.
AC_CHECK_LIB([m], [log10], [], [
    AC_MSG_ERROR([libm (math.h) log10() not found.])
])




# Checks for header files.
if test "$build_mac" = "yes" || test "$build_linux" = "yes"; then
    AC_CHECK_HEADERS([argp.h])
elif test "$build_windows" = "yes"; then
    AC_CHECK_HEADERS([windows.h wchar.h])
fi
AC_CHECK_HEADERS([stdio.h string.h stdlib.h time.h inttypes.h malloc.h stdint.h sys/time.h sys/timeb.h unistd.h])



# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T



# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strdup strndup error])
if test "$build_mac" = "yes" || test "$build_linux" = "yes"; then
    AC_CHECK_FUNCS([asprintf])
fi



AC_OUTPUT
