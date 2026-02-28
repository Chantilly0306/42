NAME = ft_hexdump
SRCS = ft_hexdump.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)