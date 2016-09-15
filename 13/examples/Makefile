CC = g++

CPPFLAGS = -g -std=c++11

LDFLAGS = -g

SOURCES= classes-and-inheritance.cc

OBJECTS= $(sources:.cc=.o)

EXECUTABLES = classes-and-inheritance

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES) 
	$(CC) $(LDFLAGS) $(SOURCES) -o $@


