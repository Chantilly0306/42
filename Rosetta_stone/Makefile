CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = rush02.h
objects = check_input.o converter.o main.o parser.o print_outcome.o utility.o

rush-02: $(objects)
	$(CC) $(CFLAGS) $^ -o rush-02

$(objects): %.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: fclean

fclean:
	rm -f rush-02
	rm -f *.o all