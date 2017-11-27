/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:58:29 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 16:56:37 by gelambin         ###   ########.fr       */
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

void			wxor(uint64_t tab[], uint64_t val, int offset)
{
	tab[offset / 64] ^= val << (offset % 64);
	if (offset % 64 != 0)
		tab[offset / 64 + 1] ^= val >> (64 - offset % 64);
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
