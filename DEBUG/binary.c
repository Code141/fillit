#include <unistd.h>
#include <stdio.h>

void	show_tetriminos(int	tetriminos)
{
	int		i;
	char	str[16];

	i = 0;
	printf("%d\n", tetriminos);

	while (i < 16)
	{
		if (tetriminos & 1)
			str[i] = 'X';
		else
			str[i] = '.';
		tetriminos = tetriminos >> 1;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (str[i] == 'X')
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (!((i+1) % 4))
			write(1, " ", 1);
		i++;
	}	
	write(1, "\n", 4);
	
	write(1, str, 4);
	write(1, "\n", 1);
	write(1, str + 4, 4);
	write(1, "\n", 1);
	write(1, str + 8, 4);
	write(1, "\n", 1);
	write(1, str + 12, 4);
	write(1, "\n", 1);
	write(1, "\n", 1);
}
