# Makefile
FLAGS = -g -Wall -std=gnu99 -pedantic -lm -O3
TARGETS = gs pds
OBJECTS = gs.o pds.o help.o sle.o

all : ${TARGETS}

gs : sle.o help.o gs.o
	gcc -o $@ $? ${FLAGS}

pds : sle.o help.o pds.o
	gcc -o $@ $? ${FLAGS}

%.o : %.c
	gcc -c -o $@ $? ${FLAGS} -I.

clean :
	rm -f *~ ${OBJECTS} ${TARGETS}

tar:
	tar cvfz ep1.tgz Makefile *.c *.h *.pdf

