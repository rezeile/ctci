CC = g++

CPPFLAGS = -g -std=c++11

LDFLAGS = -g

SOURCES= last-k-lines.cc

OBJECTS= $(SOURCES:.cc=.o)

EXECUTABLES = $(SOURCES:.cc=)

all: $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES) 
	$(CC) $(LDFLAGS) $(SOURCES) -o $@


