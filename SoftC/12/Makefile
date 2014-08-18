# Makefile

OBJECTS = main5.o lhs.o
HEADERS = lhs.h
TARGET  = lhs

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}