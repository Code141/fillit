/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:58:29 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/25 21:07:21 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

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
