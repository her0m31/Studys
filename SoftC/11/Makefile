# Makefile

OBJECTS = main3.o dijkstra2.o
HEADERS = dijk2.h
TARGET  = test

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}