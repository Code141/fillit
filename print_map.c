/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:30:12 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/22 20:25:27 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
#include "solve.h"

void	put_piece(char *str, t_fillit *ctx, int index, const uint16_t *pieces)
{
	int			i;
	int			offset;
	uint16_t	piece;

	i = 0;
	offset = ctx->offsets[(ctx->pieces_permut)[index]];
	piece = (uint16_t)(pieces[(ctx->pieces_permut)[index]]);
	while (i < 16)
	{
		if (piece) /* */
			str[(i % 4)	* ctx->map_size + offset] = 'A' + index;
		else
			str[(i % 4)	* ctx->map_size + offset] = '.';
		piece <<= 1;
		i++;
	}
}

int		print_map(const uint16_t *pieces, t_fillit *ctx)
{
	int		i;
	int		str_size;
	char	*str;

	i = 0;
	str_size = (ctx->map_size + 1) * ctx->map_size;
	str = (char*)malloc(sizeof(*str) * str_size);
	if (!str)
		return (0);
	/*fill map with dot*/
	/*put \n */
	while (i < ctx->piece_count)
		put_piece(str, ctx, i++, pieces);
	write (1, str, str_size);
	free(str);
	return (1);
}
