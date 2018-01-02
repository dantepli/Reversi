server.out: compile
	g++ -pthread -o ../../exe/server.out *.o
	rm -f *.o

compile:
	g++ -g -Iinclude/ -c src/*.cpp main.cpp

run:
	./../../exe/server.out
