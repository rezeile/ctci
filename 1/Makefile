#rotate-matrix: rotate-matrix.cc
	#g++ -std=c++11 -o rotate-matrix rotate-matrix.cc

#print-outer: print-outer.cc
	#g++ -o print-outer print-outer.cc

#1.5: 1.5.cc
	#g++ -o 1.5 1.5.cc

#1.4: 1.4.cc
	#c++  -o0  -g -o 1.4 1.4.cc

all: is-rotation set-to-zero.o print-matrix.o set-to-zero

set-to-zero.o: set-to-zero.cc
	g++ -std=c++11 -g -c set-to-zero.cc

print-matrix.o: ../util/print-matrix.cc
	g++ -std=c++11 -g -c ../util/print-matrix.cc

set-to-zero:
	g++ -std=c++11 -g -o stz print-matrix.o set-to-zero.o

is-rotation: is-rotation.cc
	g++ -std=c++11 -g -o is-rotation is-rotation.cc

clean:
	rm -rf stz set-to-zero.o 1.4 1.5 1.4.dSYM
