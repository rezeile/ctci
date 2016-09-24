CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= min-height.cc balanced-bin-tree.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
