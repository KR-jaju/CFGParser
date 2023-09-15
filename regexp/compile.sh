make -C ../../lib/libds
make -C ../../lib/libft
gcc -g *.c -I../../include -I../../lib/libds -I../../lib/libft ../alloc.c ../../lib/libft/libft.a ../../lib/libds/libds.a