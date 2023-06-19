CC=gcc
OBJ=main.o example.o
EXEC=program
CFLAGS=-Wall -Werror -g

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c example.h
	$(CC) $(CFLAGS) -c main.c

example.o: main.c example.h
	$(CC) $(CFLAGS) -c example.c

clean:
	rm -f $(OBJ) $(EXEC)
