OBJ=extension1.o extension_loader.o maintest.o

TARGET=extest

CXX=g++
CC=gcc

CFLAGS=-O0 -g

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)
