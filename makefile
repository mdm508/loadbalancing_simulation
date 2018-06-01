#makefile
# \ for line break
# this is variable for which compiler to use
CC = g++
CFLAGS = -c -Wall 
OBJFILES = main.o UnitList.o Unit.o  Write.o
# this is the name of target program
TARGET = run

all: $(TARGET) 

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

UnitList.o: UnitList.cpp
	$(CC) $(CFLAGS) UnitList.cpp 

Unit.o: Unit.cpp
	$(CC) $(CFLAGS) Unit.cpp

Write.o: Write.cpp
	$(CC) $(CFLAGS) Write.cpp

clean:
	rm -f $(OBJFILES) $(TARGET)
