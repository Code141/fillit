/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:10:21 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 20:19:09 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "input.h"
#include "solve.h"

int	main(int argc, char *argv[])
{
	uint16_t	*pieces;
	int			piece_count;

	if (argc != 2)
	{
		write(2, "usage: fillit source_file\n", 26);
		return (1);
	}
	piece_count = read_pieces_from_file(argv[1], &pieces);
	if (piece_count < 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	solve(pieces, piece_count);
	free(pieces);
	return (0);
}
