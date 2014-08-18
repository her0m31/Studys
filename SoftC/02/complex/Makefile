# Makefile for complex

OBJECTS = complex_main.o complex.o complex_add.o complex_min.o complex_mul.o complex_div.o
HEADERS = complex.h
TARGET  = complex

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -o $@ ${OBJECTS} -lm

${OBJECTS}: ${HEADERS}