# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:02:56 by gelambin          #+#    #+#              #
#    Updated: 2017/11/27 17:05:05 by gelambin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
