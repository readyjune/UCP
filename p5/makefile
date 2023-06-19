CC=gcc
OBJ=main.o arrays.o
EXEC=program
CFLAGS=-Wall -Werror -g

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c arrays.h
	$(CC) $(CFLAGS) -c main.c

arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

clean:
	rm -f $(OBJ) $(EXEC)
