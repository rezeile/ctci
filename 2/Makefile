all: list.o kth.o kth 

list.o: list.cc list.h
	g++ -c list.cc
kth.o: kth_to_last.cc node.h list.h
	g++ -c kth_to_last.cc
kth: kth_to_last.cc node.h list.h list.cc
	g++ -std=c++11 -o kth_to_last kth_to_last.o list.o

remove-duplicates: remove-duplicates.cc
	g++ -g -o remove-duplicates remove-duplicates.cc
clean:
	rm remove-duplicates kth_to_last.o list.o kth_to_last
