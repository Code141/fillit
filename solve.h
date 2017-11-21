/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:21 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/22 00:10:47 by sboilard         ###   ########.fr       */
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
	unsigned char	pieces_permut[26];
	uint64_t		pieces[];
}				t_fillit;

void			solve(const uint16_t *pieces, int piece_count);

#endif
