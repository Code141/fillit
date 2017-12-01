/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:55:34 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/01 16:43:02 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H

# include <inttypes.h>

# define SHR_64_GUARD(val, off) ((off) < 64 ? (val) >> (off) : 0)

# define WOL(t, o) ((t)[(o) / 64] >> ((o) % 64))
# define WOH(t, o) ((o) % 64 > 0 ? (t)[(o) / 64 + 1] << (64 - (o) % 64) : 0)
# define WO(t, o) (WOH(t, o) | WOL(t, o))
# define WAND(t, o, v) (WO(t, o) & (v))

unsigned int	count_bits(uint16_t val);
void			wxor(uint64_t tab[], uint64_t val, int offset);
size_t			initial_map_size(const uint16_t *pieces, int piece_count);

#endif
