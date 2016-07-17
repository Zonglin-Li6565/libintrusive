ACLOCAL_AMFLAGS = -I m4

CFLAGS = -Wall -std=c99 -I../include -O2
LDFLAGS = -I../include

lib_LTLIBRARIES = libintrusive.la
libintrusive_la_LDFLAGS = -version-info 0:0:0
libintrusive_la_SOURCES = avltree.c linkedlist.c
include_HEADERS = ../include/avltree.h ../include/binarytree.h ../include/common.h ../include/linkedlist.h
