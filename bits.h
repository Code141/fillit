/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:55:34 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/03 20:08:59 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H

# include <inttypes.h>

unsigned int	count_bits(uint16_t val);
uint64_t		shr_64_guard(uint64_t value, int offset);
void			wxor(uint64_t tab[], uint64_t val, int offset);
uint64_t		wand(uint64_t tab[], unsigned int offset, uint64_t value);
size_t			initial_map_size(const uint16_t *pieces, int piece_count);

#endif
