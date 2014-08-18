# Makefile

OBJECTS = main4.o dfsw.o
HEADERS = dfsw.h
TARGET  = test

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}