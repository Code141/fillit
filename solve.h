/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:21 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/01 16:02:31 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <inttypes.h>

typedef struct	s_fillit
{
	uint64_t		map[7];
	int				map_size;
	int				piece_count;
	uint64_t		last_column;
	int				max_offset;
	unsigned int	offsets[26];
	uint64_t		pieces[];
}				t_fillit;

void			solve(const uint16_t *pieces, int piece_count);

#endif
