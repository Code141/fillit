NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra #-Werror

SRCS = ft_bzero.c ft_memcpy.c input.c main.c solve.c

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
