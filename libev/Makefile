# %W% %G% %U%
#
# 1984 makefile
#
# Copyright (c) 1984, Landon Curt Noll.
# All Rights Reserved.  Permission for personal, educational or non-profit
# use is granted provided this this copyright and notice are included in its
# entirety and remains unaltered.  All other uses must receive prior permission
# from Landon Curt Noll and Larry Bassel.

CFLAGS := -g -Wall -O3 -v -Ideps/libev-4.24
CXXFLAGS := $(CFLAGS)

#if -lm is removed, then the linker will not be able to find symbols defined in libev.a.
LDFLAGS := -Wl,-rpath,bin,-rpath, -lm -L./ -lev

SOURCES2 := client.c server.c

all: $(SOURCES2) libev.a 
	$(CC) $(CFLAGS) $(LDFLAGS) client.c -o bin/client
	$(CC) $(CFLAGS) $(LDFLAGS) server.c -o bin/server

libev.a:
	cd deps/libev-4.24 && ./configure && make
	cp deps/libev-4.24/.libs/libev.a ./

clean:
	rm -rf bin/*