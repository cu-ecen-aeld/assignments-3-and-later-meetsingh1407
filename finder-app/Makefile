CC= $(CROSS_COMPILE)gcc

TARGET=writer

all: $(TARGET)

$(TARGET): writer.o
	$(CC) -o $(TARGET) writer.o

writer.o: writer.c
	$(CC) -c writer.c

clean: 
	rm -f *.o $(TARGET)
