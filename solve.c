/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:51:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/01 16:47:26 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include "libft.h"
#include "bits.h"
#include "solve.h"
#include "print_map.h"

static void	refresh_context(const uint16_t *pieces, t_fillit *context)
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
	context->last_column =
		((1 << context->map_size | 1) << context->map_size | 1)
		<< (context->map_size - 1);
	context->max_offset = context->map_size * context->map_size;
}

static int	try_put_piece(t_fillit *ctx, int i)
{
	uint64_t	piece;
	int			offset;

	if (i == ctx->piece_count)
		return (1);
	piece = ctx->pieces[i];
	offset = 0;
	while (SHR_64_GUARD(piece, ctx->max_offset - offset) == 0)
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

	context = (t_fillit *)
		malloc(sizeof(*context) + sizeof(*context->pieces) * piece_count);
	if (context == NULL)
		return ;
	ft_bzero(context->map, sizeof(context->map));
	context->map_size = initial_map_size(pieces, piece_count);
	context->piece_count = piece_count;
	refresh_context(pieces, context);
	while (!try_put_piece(context, 0))
	{
		++context->map_size;
		refresh_context(pieces, context);
	}
	print_map(context);
	free(context);
}
