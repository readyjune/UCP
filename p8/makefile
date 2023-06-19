CC=gcc
CFLAGS=-Wall -g
OBJ=main.o bucket_list.o
EXEC=program

$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c bucket_list.h
	$(CC) $(CFLAGS) -c main.c

bucket_list.o: bucket_list.c bucket_list.h
	$(CC) $(CFLAGS) -c bucket_list.c

clean:
	rm -f $(OBJ) $(EXEC)
