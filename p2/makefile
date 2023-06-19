CC =gcc
CFLAGS = -Wall -Werror -ansi -pedantic
OBJ = main.o powers.o input.c
EXEC = print_powers

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c powers.h input.h
	$(CC) $(CFLAGS) -c main.c

powers.o: powers.c
	$(CC) $(CFLAGS) -c powers.c

input.o: input.c
	$(CC) $(CFLAGS) -c input.c


clean:
	rm -f $(EXEC) $(OBJ)
