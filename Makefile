CC = gcc
CFLAGS += -Wall

PREFIX = /usr

CFLAGS += $(shell pkg-config --cflags libgit2)
LDFLAGS += $(shell pkg-config --libs libgit2)
SRC=$(wildcard prompt.c modules/*.c)

all:
	$(CC) $(CFLAGS) -o prompt $(SRC) $(LDFLAGS)
	$(CC) $(CFLAGS) -o prompt_time prompt_time.c 

install: all
	@echo installing to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f prompt prompt_time ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/prompt
	@chmod 755 ${DESTDIR}${PREFIX}/bin/prompt_time

uninstall:
	@echo uninstalling from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/prompt
	@rm -f ${DESTDIR}${PREFIX}/bin/prompt_time

.PHONY: all install uninstall
