/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:51:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/23 19:08:41 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include "libft_str.h"
#include "solve.h"
#include "print_map.h"

/*
** Does not work for size < 4.
*/

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

static void	move(unsigned int *tab, int from, int to)
{
	unsigned int	t;

	while (from < to)
	{
		t = tab[from];
		tab[from] = tab[from + 1];
		tab[from + 1] = t;
		++from;
	}
	while (from > to)
	{
		t = tab[from];
		tab[from] = tab[from - 1];
		tab[from - 1] = t;
		--from;
	}
}

static int	try_put_piece(t_fillit *ctx, uint64_t piece)
{
	uint64_t	last_column;
	int			max_offset;
	int			i;

	last_column =
		((1 << ctx->map_size | 1) << ctx->map_size | 1) << (ctx->map_size - 1);
	max_offset = ctx->map_size * ctx->map_size;
	i = 0;
	while (max_offset - i >= 64 || piece >> (max_offset - i) == 0)
	{
		if (WAND(ctx->map, i, piece) == 0)
			return (i);
		if ((piece << (i % ctx->map_size) & last_column) != 0)
			i += ctx->map_size - i % ctx->map_size;
		else
			++i;
	}
	return (-1);
}

static int	solve_aux(t_fillit *ctx, int i)
{
	int			j;
	int			offset;
	uint64_t	piece;

	j = i;
	while (j < ctx->piece_count)
	{
		piece = ctx->pieces[ctx->pieces_permut[j]];
		if ((offset = try_put_piece(ctx, piece)) < 0)
			return (0);
		ctx->map[offset / 64] ^= piece << (offset % 64);
		ctx->map[offset / 64 + 1] ^= piece >> (64 - offset % 64);
		move(ctx->pieces_permut, j, i);
		if (solve_aux(ctx, i + 1))
		{
			ctx->offsets[ctx->pieces_permut[i]] = offset;
			return (1);
		}
		move(ctx->pieces_permut, i, j);
		ctx->map[offset / 64] ^= piece << (offset % 64);
		ctx->map[offset / 64 + 1] ^= piece >> (64 - offset % 64);
		++j;
	}
	return (i == j);
}

void		solve(const uint16_t *pieces, int piece_count)
{
	t_fillit	*context;
	int			i;

	context = (t_fillit *)
		malloc(sizeof(*context) + sizeof(*context->pieces) * piece_count);
	if (context == NULL)
		return ;
	ft_bzero(context->map, sizeof(context->map));
	context->map_size = 4;
	context->piece_count = piece_count;
	i = 0;
	while (i < piece_count)
	{
		context->pieces_permut[i] = i;
		++i;
	}
	resize_pieces(pieces, context);
	while (!solve_aux(context, 0))
	{
		++context->map_size;
		resize_pieces(pieces, context);
	}
	print_map(context);
	free(context);
}
