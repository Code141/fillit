/*-DEBUG----------------------------------------------------------------------*/
void	show_tetriminos(int tetriminos);
/*----------------------------------------------------------------------------*/

#include <unistd.h>
#include <stdlib.h>
#include "input.h"
#include "solve.h"

int	main(int argc, char **argv)
{
	uint16_t	*pieces;
	int			piece_count; 
	
	if (argc != 2)
	{
		write(2, "Usage: fillit target_file\n", 27);// SORTIE ERROR
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
