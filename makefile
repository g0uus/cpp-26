#
#
#

CPP_FLAGS = --std=c++26 -g -o0 -Wall -Wextra -pedantic

SOURCES = main.cpp
OBJECTS = cpp-26.o
TARGET = cpp-26


all: ${TARGET}


cpp-26.o : main.cpp concept1.h concept2.h grh_version.h picture1.h
	g++ -c ${CPP_FLAGS} -o cpp-26.o main.cpp


picture1.h : GeoObj.h

cpp-26: ${OBJECTS}
	g++ ${CPP_FLAGS} -o ${TARGET} ${OBJECTS}

clean:
	rm -rf ${TARGET} ${OBJECTS}

run: clean ${TARGET}
	./${TARGET}
