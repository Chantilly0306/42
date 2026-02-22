NAME1 = test_strdup
NAME2 = test_range
SRCS1 = ft_strdup.c main.c
SRCS2 = ./ft_range/ft_range.c ./ft_range/main.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
CFLAGS += -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	cc -o $(NAME1) $(OBJS1)
$(NAME2): $(OBJS2)
	cc -o $(NAME2) $(OBJSS2)

clean:
	rm -f $(OBJS1) $(OBJS2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)