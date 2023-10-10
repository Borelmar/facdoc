#!/bin/bash
rm -rf ./configure \
    ./configure~ \
    ./Makefile.in \
    ./autom4te.cache \
    ./aclocal.m4 \
    ./*.log

rm -rf build/*

autoreconf -i

exit 0
