NAME=CFGParser
SRCS=$(wildcard *.c) $(wildcard ./src/*/*.c)
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./libds
	cc -o $(NAME) $^ ./libft/libft.a ./libds/libds.a

%.o : %.c
	cc -c $< -o $@ $(DEBUG) -I./include -I./libft -I./libds

clean:
	make -C ./libft fclean
	make -C ./libds fclean
	rm -f $(OBJS)

fclean:
	make -C ./libft fclean
	make -C ./libds fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all
