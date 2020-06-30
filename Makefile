CC = gcc
CFLAGS += -Wall

CFLAGS += $(shell pkg-config --cflags libgit2)
LDFLAGS += $(shell pkg-config --libs libgit2)
SRC=$(wildcard *.c modules/*.c)

all:
	$(CC) $(CFLAGS) -o prompt $(SRC) $(LDFLAGS)
