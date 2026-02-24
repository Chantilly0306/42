NAME = ft_display_file
SRCS = ft_display_file.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -Wall -Wextra -Werror

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)