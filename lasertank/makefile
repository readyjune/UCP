CC=gcc
OBJ=main.o arrays.o direction.o ucpSleep.o simple.o shoot.o mirror.o mirror2.o linkedlist.o
EXEC=program
CFLAGS=-Wall -Werror -g

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c arrays.h
	$(CC) $(CFLAGS) -c main.c

arrays.o: arrays.c arrays.h direction.h ucpSleep.h simple.h shoot.h mirror.h
	$(CC) $(CFLAGS) -c arrays.c

direction.o: direction.c
	$(CC) $(CFLAGS) -c direction.c

ucpSleep.o: ucpSleep.c ucpSleep.h
	$(CC) $(CFLAGS) -c ucpSleep.c

simple.o: simple.h
	$(CC) $(CFLAGS) -c simple.c

shoot.o: shoot.c 
	$(CC) $(CFLAGS) -c shoot.c

mirror.o: mirror.c
	$(CC) $(CFLAGS) -c mirror.c

mirror2.o: mirror2.c
	$(CC) $(CFLAGS) -c mirror2.c

linkedlist.o: linkedlist.c
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f $(OBJ) $(EXEC)
