# use tcc to compile
CC = tcc
# -Wall: turn on most, but not all, compiler warnings
CFLAGS = -Wall
# the target executable file
TARGET = id3r

# typing 'make' will invoke the first target entry; here: default
default: $(TARGET)

# to build the TARGET executable file we need the source files
# id3v1.o
$(TARGET): id3v1.o
	$(CC) $(CFLAGS) -o $(TARGET) id3v1.o

# to create the object file id3v1.o we need the source files
# id3v1.c
id3v1.o: id3v1.c
	$(CC) $(CFLAGS) -c id3v1.c

# starting over from scratch, removes all object files and the executable file
clean:
	rm $(TARGET) *.o
