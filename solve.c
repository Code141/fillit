/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:51:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 16:56:51 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include "libft.h"
#include "bits.h"
#include "solve.h"
#include "print_map.h"

static void	resize_pieces(const uint16_t *pieces, t_fillit *context)
{
	int			i;
	int			j;
	uint16_t	p;
	uint64_t	r;

	i = 0;
	while (i < context->piece_count)
	{
		p = pieces[i];
		r = 0;
		j = 0;
		while (j++ < 4)
		{
			r = (r << context->map_size) | (p >> 12 & 0xf);
			p <<= 4;
		}
		context->pieces[i] = r;
		++i;
	}
}

static int	try_put_piece(t_fillit *ctx, int i)
{
	int			max_offset;
	int			offset;
	uint64_t	piece;

	if (i == ctx->piece_count)
		return (1);
	piece = ctx->pieces[i];
	offset = 0;
	max_offset = ctx->map_size * ctx->map_size;
	while (offset < max_offset && (max_offset - offset >= 64 || piece >> (max_offset - offset) == 0))
	{
		if (WAND(ctx->map, offset, piece) == 0)
		{
			wxor(ctx->map, piece, offset);
			if (try_put_piece(ctx, i + 1))
			{
				ctx->offsets[i] = offset;
				return (1);
			}
			wxor(ctx->map, piece, offset);
		}
		if ((piece << (offset % ctx->map_size) & ctx->last_column) != 0)
			offset += ctx->map_size - offset % ctx->map_size;
		else
			++offset;
	}
	return (0);
}

void		solve(const uint16_t *pieces, int piece_count)
{
	t_fillit	*context;

	if (!(context = (t_fillit *)
		malloc(sizeof(*context) + sizeof(*context->pieces) * piece_count)))
		return ;
	ft_bzero(context->map, sizeof(context->map));
	context->map_size = initial_map_size(pieces, piece_count);
	context->piece_count = piece_count;
	resize_pieces(pieces, context);
	context->last_column =
		((1 << context->map_size | 1) << context->map_size | 1) << (context->map_size - 1);
	while (!try_put_piece(context, 0))
	{
		++context->map_size;
	context->last_column =
		((1 << context->map_size | 1) << context->map_size | 1) << (context->map_size - 1);
		resize_pieces(pieces, context);
	}
	print_map(context);
	free(context);
}
