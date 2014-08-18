# Makefile

OBJECTS = main.o make_tree.o add.o reference.o print.o search.o fix.o delete.o list_adrb.o ua_down.o
HEADERS = adrb.h
TARGET  = Addressbook 

all: ${TARGET}

clean: 
		rm -f ${TARGET} ${OBJECTS}

${TARGET}: ${OBJECTS}
		cc -g -o $@ ${OBJECTS}

${OBJECTS}: ${HEADERS}