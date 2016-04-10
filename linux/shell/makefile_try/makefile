CC = g++
FLAGS = -Wall -g

OBJ = main.o pub.o
EXEC = myapp

EXEC: $(OBJ)
	$(CC) -o $(EXEC) $(FLAGS) $(OBJ)

pub.o:
	$(CC) $(FLAGS) -o pub.o -c pub.cc

main.o:
	$(CC) $(FLAGS) -o main.o -c main.cc

clean:
	rm -rf *.o $(EXEC)
