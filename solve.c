int		resize_pieces(uint16_t *pieces, int count, int size, uint64_t **result)
{
	int			i;
	int			j;
	uint16_t	p;
	uint64_t	r;
	// IF (SIZE > 4) CASE !
	i = 0;
	while (i <count)
	{
		p = pieces[i];
		r = 0;
		j = 0;
		while(j++ < 4)
		{
			r = (r << size) | (p >> 12 & 0xf);
			p <<= 4;
		}
		result[i] = r;
	}
}

void	next_piece(uint16_t *piece, uint64_t map)
{
	
}

void	solve(uint16_t **pieces, int piece_count)
{
	int			i;
	int			current_piece;
	uint64_t	*map;

	i = 0;
	while (current_piece < piece_count)
		next_piece((*pieces) + (current_piece + i++), map);
//	print(pieces, piece_count, map);
}
