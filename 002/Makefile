CPP = g++
OFLAG = -o
TARGET = a.out 
OBJS = main.o student.o

$(TARGET): $(OBJS)
	$(CPP) $(OFLAG) $(TARGET) $(OBJS)
main.o: main.cpp student.o
student.o: student.cpp

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJS)
