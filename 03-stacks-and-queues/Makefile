all: list.o towers.o towers three-stacks-naive plates-test[

list.o: ../util/list.cc ../util/list.h
	g++ -g -std=c++11 -c ../util/list.cc

towers.o: towers.cc
	g++ -g -std=c++11 -c towers.cc

towers: ../util/list.cc towers.cc
	g++ -g -std=c++11 -o towers towers.o list.o

three-stacks-naive: three-stacks-naive.cc three-stacks.h
	g++ -g -o three-stacks-naive three-stacks-naive.cc

plates-test: plates-test.cc plates.h
	g++ -g -o plates-test plates-test.cc

constant-min: constant-min.cc constant-min.h
	g++ -g -std=c++11 -o constant-min constant-min.cc

my-queue: my-queue.cc my-queue.h
	g++ -g -std=c++11 -o my-queue my-queue.cc

sort-stack: sort-stack.cc 
	g++ -g -std=c++11 -o sort-stack sort-stack.cc

shelter: shelter.cc shelter.h
	g++ -g -std=c++11 -o shelter shelter.cc

clean:
	rm three-stacks-naive list.o towers.o towers plates-test constant-min sort-stack
