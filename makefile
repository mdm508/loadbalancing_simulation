#makefile
# \ for line break
# this is variable for which compiler to use
CC = g++
CFLAGS = -c -Wall 
OBJFILES = main.o UnitList.o  Write.o
# this is the name of target program
TARGET = run

all: $(TARGET) 

$(TARGET): $(OBJFILES)
	$(CC) main.o UnitList.o Write.o -o $(TARGET)

main.o:
	$(CC) $(CFLAGS) main.cpp

UnitList.o: 
	$(CC) $(CFLAGS) UnitList.cpp 

Write.o:
	$(CC) $(CFLAGS) Write.cpp

clean:
	rm -f $(OBJFILES) $(TARGET)
