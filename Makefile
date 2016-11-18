CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=
CFLAGS=
LDFLAGS=
LDLIBS=

BINNAME=mastermind
SRCS=main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: mastermind

mastermind: $(OBJS)
    $(CXX) $(LDFLAGS) -o $(MASTERMIND) $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
    rm -f ./.depend
    $(CXX) $(CPPFLAGS) -MM $^>>./.dep

clean:
    $(RM) $(OBJS)

dist-clean: clean
    $(RM) $(BINNAME)

include .depend