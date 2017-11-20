NAME = fillit

CC = gcc
#CFLAGS = -Wall -Wall -Werror
CFLAGS = -Wall -Wall

SRCS = main.c

OBJS = $(SRCS:./srcs/.c=.o)

all: $(NAME)

$(NAME):

clean:
	/bin/rm -f $(OBJS)

fclean:
	/bin/rm -f $(NAME) $(OBJS)

re: fclean re

.PHONY: $(SRCS) all clean fclean re
