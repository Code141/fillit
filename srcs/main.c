/*-DEBUG----------------------------------------------------------------------*/
void	show_tetriminos(int tetriminos);
/*----------------------------------------------------------------------------*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*tetriminos;

	int i;
	if (argc == 2)
	{
		i = 0;
		while (i < 5)	
			show_tetriminos(i++);
	}
	else
	{
		write(2, "Usage: fillit target_file\n", 27);
		return (1);
	}
	return (0);
}
