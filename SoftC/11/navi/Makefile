# Makefile

OBJECTS = main5.o read.o navi.o
HEADERS = navi.h
TARGET  = test

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}