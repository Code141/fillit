/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:51:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/21 19:27:26 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>

/*
** Does not work for size < 4.
*/

static void	resize_pieces(const uint16_t *pieces, int count, int map_size,
							uint64_t *result)
{
	int			i;
	int			j;
	uint16_t	p;
	uint64_t	r;

	i = 0;
	while (i < count)
	{
		p = pieces[i];
		r = 0;
		j = 0;
		while (j++ < 4)
		{
			r = (r << map_size) | (p >> 12 & 0xf);
			p <<= 4;
		}
		result[i] = r;
	}
}

void		solve(const uint16_t *pieces, int piece_count)
{
	uint64_t	*resized_pieces;
	int			i;

	i = 4;
	resized_pieces = (uint64_t *)malloc(sizeof(*resized_pieces) * piece_count);
	if (resized_pieces == NULL)
		return ;
	while (1)
	{
		resize_pieces(pieces, piece_count, i, resized_pieces);
		/* Try to solve it. */
		if (1/* Was it solved? */)
			break ;
		else
			++i; /* Try with a map one unit larger. */
	}
	/* Print result. */
	free(resized_pieces);
}
