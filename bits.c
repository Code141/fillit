/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:58:29 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/03 17:27:59 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <ctype.h>
#include "libft.h"

size_t			initial_map_size(const uint16_t *pieces, int piece_count)
{
	size_t	size;

	size = ft_sqrti(piece_count * 4);
	if (size == 2 && pieces[0] != 0x0033)
		size = 3;
	if (size == 3 && (pieces[0] == 0x1111 || pieces[0] == 0x000f
		|| pieces[1] == 0x1111 || pieces[1] == 0x000f))
		size = 4;
	return (size);
}

int				shr_64_guard(uint64_t val, int off)
{
	return ((off) < 64 ? (val) >> (off) : 0);
}

void			wxor(uint64_t tab[], uint64_t val, int offset)
{
	tab[offset / 64] ^= val << (offset % 64);
	if (offset % 64 != 0)
		tab[offset / 64 + 1] ^= val >> (64 - offset % 64);
}

int				wand(uint64_t t[], unsigned int o, uint64_t v)
{
	uint64_t	wol;
	uint64_t	woh;

	wol = t[o / 64] >> (o % 64);
	woh = o % 64 > 0 ? t[o / 64 + 1] << (64 - o % 64) : 0;
	return ((wol | woh) & v);
}

unsigned int	count_bits(uint16_t val)
{
	unsigned int	count;

	count = 0;
	while (val != 0)
	{
		count += val & 1;
		val >>= 1;
	}
	return (count);
}
