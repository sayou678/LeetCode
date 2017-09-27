CC=gcc
CFLAGS=-c -g
LDFLAGS=
SOURCES=main.c sll.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=list

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
