# %W% %G% %U%
#
# 1984 makefile
#
# Copyright (c) 1984, Landon Curt Noll.
# All Rights Reserved.  Permission for personal, educational or non-profit
# use is granted provided this this copyright and notice are included in its
# entirety and remains unaltered.  All other uses must receive prior permission
# from Landon Curt Noll and Larry Bassel.


all: bin/echo-server bin/echo-client

bin/echo-server: server.c
	cc server.c -o bin/echo-server

bin/echo-client: client.c
	cc client.c -o bin/echo-client

clean:
	rm -rf bin/*