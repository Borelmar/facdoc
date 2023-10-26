#ifndef ___FCD___ASPRINTF___H__
#define ___FCD___ASPRINTF___H__

#ifndef HAVE_ASPRINTF
    extern int asprintf (char **str, const char *fmt, ...);
    extern int vasprintf (char **str, const char *fmt, va_list args);
#else
#   define _GNU_SOURCE /* See feature_test_macros(7) */
#   include <stdio.h>
#endif

#endif /* ___FCD___ASPRINTF___H__ */
