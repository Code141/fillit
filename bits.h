/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:55:34 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/03 17:27:41 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H

# include <inttypes.h>

unsigned int	count_bits(uint16_t val);
int				wand(uint64_t t[], unsigned int o, uint64_t v);
int				shr_64_guard(uint64_t val, int off);
void			wxor(uint64_t tab[], uint64_t val, int offset);
size_t			initial_map_size(const uint16_t *pieces, int piece_count);

#endif
