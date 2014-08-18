# Makefile

OBJECTS = main2.o bst.o
HEADERS = bst.h
TARGET  = test
all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}