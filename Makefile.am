EXTRA_DIST = m4
ACLOCAL_AMLOCAL = -I m4 --install
BUILT_SOURCES = src/fcd/parser.c src/fcd/lexer.c src/fcd/parser.h
AM_YFLAGS = --debug -d

bin_PROGRAMS = facdoc
facdoc_SOURCES = src/util/strarr_data_size.c src/util/fcd_asprintf.h src/util/strrealloc.c src/util/mallocn.c src/util/astrcat.c src/util/fcd_asprintf.c src/util/strarrcat.c src/util/chrmult.c src/util/wildcard.c src/util/base64.c src/util/fferror.c src/util/util.h src/util/dicount.c src/util/stralloc.c src/util/maxofa.c src/util/size_t2str.c src/util/astrncat.c src/util/fgetsize.c src/facdoc.h src/fcd/fcd.c src/fcd/print_fcd_st.h src/fcd/fcd.h src/fcd/errors.h src/fcd/print_fcd_st.c src/fcd/fcd_st2gv.c src/fcd/fcd_st2gv.h src/facdoc.c src/fcd/parser.y src/fcd/lexer.l

facdoc_CFLAGS = -std=gnu99 -Wall \
				-I../src/ \
				-I../src/fcd/ \
				-I../src/util/ \
				-I../src/translators/html/

# -I../src/util/ \
# -I../src/fcd/ \
# -I../src/translators/html

AM_LDFLAGS = -lm
if WINDOWS
facdoc_CFLAGS += -mwindows # for GUI, see mingw help
endif

facdoc_LDADD = $(lib_LTLIBRARIES)
