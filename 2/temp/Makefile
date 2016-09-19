all: list.o list-hickup.o list-hickup

list.o: ../list.cc 
	g++ -g -std=c++11 -c ../list.cc

list-hickup.o: list-hickup.cc
	g++ -g -std=c++11 -c list-hickup.cc

list-hickup: list-hickup.cc
	g++ -g -std=c++11 -o list-hickup list.o list-hickup.o

clean:
	rm list-hickup
