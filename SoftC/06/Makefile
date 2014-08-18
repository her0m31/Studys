# Makefile

OBJECTS = main7.o quicks.o bubbles.o simples.o
HEADERS = sort.h
TARGET  = sort

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc  -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}