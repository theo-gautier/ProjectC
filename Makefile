CC=g++
CFLAGS=-Wall
EXEC=cypher
LIB=-lreadline


all: $(EXEC) cleanfunctions

cypher: cypher.o DecodeCesar.o
	$(CC) -o $@ $^


DecodeCesar.o: DecodeCesar.cpp
	$(CC) -o $@ -c $^ $(CFLAGS)

cypher.o: cypher.cpp DecodeCesar.hpp
	$(CC) -o $@ -c cypher.cpp $(CFLAGS)


cleanfunctions:
	rm -f *.o

clean:
	rm cypher
