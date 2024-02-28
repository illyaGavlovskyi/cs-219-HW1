adder: main.o
	g++ main.o -o adder
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o adder