/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:30:12 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/23 13:50:46 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "solve.h"

static void	put_piece(char *str, t_fillit *ctx, int index)
{
	int			i;
	int			offset;
	uint64_t	piece;

	i = 0;
	offset = ctx->offsets[index];
	piece = ctx->pieces[index];
	while (i < 64)
	{
		if (piece & 1)
			str[i + offset + (i + offset) / ctx->map_size] = 'A' + index;
		piece >>= 1;
		++i;
	}
}

void		print_map(t_fillit *ctx)
{
	int		i;
	int		j;
	int		str_size;
	char	*str;

	str_size = (ctx->map_size + 1) * ctx->map_size;
	str = (char *)malloc(sizeof(*str) * str_size);
	if (!str)
		return ;
	j = 0;
	while (j != str_size)
	{
		str[j] = (j % (ctx->map_size + 1) == ctx->map_size) ? '\n' : '.';
		j++;
	}
	i = 0;
	while (i < ctx->piece_count)
		put_piece(str, ctx, i++);
	write(1, str, str_size);
	free(str);
}
