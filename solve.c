/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:51:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 13:19:50 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include "libft_math.h"
#include "libft_str.h"
#include "bits.h"
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

static int	try_put_piece(t_fillit *ctx, uint64_t piece, int i)
{
	uint64_t	last_column;
	int			max_offset;
	int			stop;

	last_column =
		((1 << ctx->map_size | 1) << ctx->map_size | 1) << (ctx->map_size - 1);
	max_offset = ctx->map_size * ctx->map_size;
	if (i == 0)
		stop = max_offset;
	else if ((piece << ((i - 1) % ctx->map_size) & last_column) != 0)
		return (-1);
	else
		stop = i + ctx->map_size - i % ctx->map_size;
	while (i < stop && (max_offset - i >= 64 || piece >> (max_offset - i) == 0))
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
		offset = -1;
		while ((offset = try_put_piece(ctx, piece, offset + 1)) >= 0)
		{
			wxor(ctx->map, piece, offset);
			ft_swap(ctx->pieces_permut + j, ctx->pieces_permut + i);
			if (solve_aux(ctx, i + 1))
			{
				ctx->offsets[ctx->pieces_permut[i]] = offset;
				return (1);
			}
			ft_swap(ctx->pieces_permut + i, ctx->pieces_permut + j);
			wxor(ctx->map, piece, offset);
		}
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
	context->map_size = ft_sqrti(piece_count * 4);
	context->piece_count = piece_count;
	i = 0;
	while (i < piece_count)
	{
		context->pieces_permut[i] = i;
		if ((pieces[i] & 0xffcc) && context->map_size == 2)
			context->map_size = 3;
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
