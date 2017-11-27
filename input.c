/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:09:29 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 16:29:36 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "bits.h"

static int		piece_is_valid(uint16_t piece)
{
	if (piece == 0x0033)
		return (1);
	return (count_bits(piece) == 4
			&& count_bits(piece & (piece & 0x7777) << 1)
			+ count_bits(piece & piece << 4) == 3);
}

static uint16_t	encode_piece(char *buffer)
{
	uint16_t	piece;
	int			i;

	piece = 0;
	i = 19;
	while (i >= 0)
	{
		if (i % 5 == 4)
		{
			if (buffer[i] != '\n')
				return (0);
		}
		else if (buffer[i] == '#' || buffer[i] == '.')
			piece = (piece << 1) | (buffer[i] == '#');
		else
			return (0);
		--i;
	}
	if (piece == 0)
		return (0);
	while ((piece & 0x1111) == 0)
		piece >>= 1;
	while ((piece & 0x000f) == 0)
		piece >>= 4;
	return (piece_is_valid(piece) ? piece : 0);
}

static int		read_pieces_from_fd(int fd, uint16_t **result)
{
	char		buffer[20];
	uint16_t	pieces[26];
	int			piece_count;
	int			read_size;

	piece_count = 0;
	while (piece_count < 26 && (read_size = read(fd, buffer, 20)) == 20)
	{
		pieces[piece_count] = encode_piece(buffer);
		if (pieces[piece_count++] == 0)
			return (-1);
		if ((read_size = read(fd, buffer, 1)) == 0)
		{
			*result = (uint16_t *)malloc(sizeof(**result) * piece_count);
			if (*result == NULL)
				return (-1);
			ft_memcpy(*result, pieces, sizeof(**result) * piece_count);
			return (piece_count);
		}
		else if (read_size < 0 || *buffer != '\n')
			return (-1);
	}
	return (-1);
}

int				read_pieces_from_file(const char *filename, uint16_t **pieces)
{
	int	fd;
	int	ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = read_pieces_from_fd(fd, pieces);
	close(fd);
	return (ret);
}
