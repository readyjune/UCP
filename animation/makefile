CC=gcc
OBJ=main.o example.o ucpSleep.o
EXEC=program
CFLAGS=-Wall -Werror -g

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c example.h
	$(CC) $(CFLAGS) -c main.c

example.o: main.c example.h ucpSleep.h
	$(CC) $(CFLAGS) -c example.c

ucpSleep.o: ucpSleep.c ucpSleep.h
	$(CC) $(CFLAGS) -c ucpSleep.c

clean:
	rm -f $(OBJ) $(EXEC)
