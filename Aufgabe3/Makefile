#
# Makefile
#
# Autor: H.Drachenfels
# Erstellt am: 18.7.2022
#

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -Wvla -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11

TARGETS = stringsort stringsort-kombi

.PHONY: all clean cppcheck

all: $(TARGETS)

stringsort: stringsort.o
	$(CC) $(CFLAGS) -o $@ $^

stringsort-kombi: stringsort-kombi.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(TARGETS) *.o

cppcheck: stringsort.c stringsort-kombi.c
	$(CPPCHECK) $^
