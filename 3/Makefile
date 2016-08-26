all: list.o towers.o towers three-stacks-naive

list.o: ../util/list.cc ../util/list.h
	g++ -g -std=c++11 -c ../util/list.cc

towers.o: towers.cc
	g++ -g -std=c++11 -c towers.cc

towers: ../util/list.cc towers.cc
	g++ -g -std=c++11 -o towers towers.o list.o

three-stacks-naive: three-stacks-naive.cc three-stacks.h
	g++ -g -o three-stacks-naive three-stacks-naive.cc
clean:
	rm three-stacks-naive list.o towers.o towers
