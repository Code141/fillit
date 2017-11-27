NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra #-Werror

SRCS =	main.c		input.c		solve.c		print_map.c		\
		ft_swap.c	ft_bzero.c	ft_memcpy.c	ft_sqrti.c		\
		bits.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re:
	$(MAKE) $(MFLAGS) fclean
	$(MAKE) $(MFLAGS) all
