NAME=CFGParser
SRCS=$(wildcard *.c) $(wildcard ./src/*/*.c)
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./libds
	cc -o $(NAME) $^

$(OBJS): $(SRCS)
	cc -c $ $^ -I./include -I./libds -I/libft

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all
