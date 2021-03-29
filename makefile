EXECUTABLE=./testa_romano.out
CC=g++
CATCH = ./lib/catch.hpp
OBJS = ./source/obj/romano.o ./source/obj/testa_romano.o

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^ 

./source/obj/testa_romano.o: ./source/testa_romano.cpp
	$(CC) -o $@ $< -c

./source/obj/romano.o: ./source/romano.cpp ./include/romano.hpp
	$(CC) -o $@ $< -c


all: $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJS)

run: $(EXECUTABLE)
	./$<

.PHONY: run clean all