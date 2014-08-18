# Makefile

OBJECTS = main6.o pq.o
HEADERS = pq.h
TARGET  = test

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}