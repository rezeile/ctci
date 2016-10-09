CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= paint-fill.cc permutations.cc  magic-index.cc staircase.cc stack-of-boxes.cc coin-change.cc paren-set.cc  subsets.cc robot-paths.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMBOLFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(SYMBOLFILES) $(PROGFILES)
