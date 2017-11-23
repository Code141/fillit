/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:21 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/23 19:22:40 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <inttypes.h>

# define WOL(t, o) ((t)[(o) / 64] >> ((o) % 64))
# define WOH(t, o) ((o) % 64 > 0 ? (t)[(o) / 64 + 1] << (64 - (o) % 64) : 0)
# define WO(t, o) (WOH(t, o) | WOL(t, o))
# define WAND(t, o, v) (WO(t, o) & (v))

typedef struct	s_fillit
{
	uint64_t		map[7];
	int				map_size;
	int				piece_count;
	unsigned int	pieces_permut[26];
	unsigned int	offsets[26];
	uint64_t		pieces[];
}				t_fillit;

void			solve(const uint16_t *pieces, int piece_count);

#endif
