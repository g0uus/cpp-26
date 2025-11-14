#
#
#

CPP_FLAGS = --std=c++26 -g -o0 -Wall -Wextra -pedantic

SOURCES = main.cpp
OBJECTS = main.o

TARGET = main


all: ${TARGET}


main.o : main.cpp concept1.h concept2.h grh_version.h picture1.h
	g++ -c ${CPP_FLAGS} -o main.o main.cpp


picture1.h : GeoObj.h

main: main.o
	g++ ${CPP_FLAGS} -o ${TARGET} main.o

clean:
	rm -rf ${TARGET} ${OBJECTS}

run: clean main
	./main
