EXTRA_DIST = m4
ACLOCAL_AMLOCAL = -I m4 --install
BUILT_SOURCES = src/fcd/parser.h src/fcd/parser.c src/fcd/lexer.c
AM_YFLAGS = -d

bin_PROGRAMS = facdoc
facdoc_SOURCES = src/fcd/parser.y src/fcd/lexer.l src/main.c

facdoc_CFLAGS = -std=gnu99 -Wall \
				-I../src/fcd/

# -I../src/util/ \
# -I../src/fcd/ \
# -I../src/translators/html

AM_LDFLAGS = -lm
if WINDOWS
facdoc_CFLAGS += -mwindows # for GUI, see mingw help
endif

facdoc_LDADD = $(lib_LTLIBRARIES)
