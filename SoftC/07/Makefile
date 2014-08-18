# Makefile

OBJECTS = main3.o linked_list.o
HEADERS = linked.h
TARGET  = test

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -o $@ ${OBJECTS} -lm

${OBJECTS}: ${HEADERS}