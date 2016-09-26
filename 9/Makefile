CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= permutations.cc  magic-index.cc staircase.cc stack-of-boxes.cc coin-change.cc paren-set.cc  subsets.cc robot-paths.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm $(PROGFILES)
