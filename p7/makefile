CC=gcc
OBJ=main.o book.o
EXEC=program
CFLAGS=-Wall -Werror -g

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c book.h
	$(CC) $(CFLAGS) -c main.c

arrays.o: book.c book.h
	$(CC) $(CFLAGS) -c book.c

clean:
	rm -f $(OBJ) $(EXEC)
