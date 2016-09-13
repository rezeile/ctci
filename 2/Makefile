all: list.o print-positions.o print-positions partition.o kth.o kth delete-middle.o delete-middle partition remove-duplicates

list.o: list.cc list.h
	g++ -c list.cc

kth.o: kth_to_last.cc node.h list.h
	g++ -c kth_to_last.cc

kth: kth_to_last.cc node.h list.h list.cc
	g++ -std=c++11 -o kth_to_last kth_to_last.o list.o

delete-middle.o: delete-from-middle.cc node.h list.h
	g++ -c -o dmiddle.o delete-from-middle.cc

delete-middle: delete-from-middle.cc
	g++ -std=c++11 -o dmiddle dmiddle.o list.o

remove-duplicates: remove-duplicates.cc
	g++ -g -o remove-duplicates remove-duplicates.cc

print-postions.o: print-positions.cc
	g++  -std=c++11 -c print-positions.cc

print-positions: print-positions.cc
	g++  -std=c++11 -o positions list.o print-positions.o 

partition.o: partition.cc
	g++ -g -std=c++11 -c partition.cc
partition: partition.cc
	g++ -g -std=c++11 -o partition list.o partition.o 
clean:
	rm partition delete-middle remove-duplicates kth_to_last.o list.o kth_to_last
