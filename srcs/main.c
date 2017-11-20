/*-DEBUG----------------------------------------------------------------------*/
void	show_tetriminos(int tetriminos);
/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv)
{
	int	*tetriminos;

	int i;

	i = 0;
	while (i < 10)	
		show_tetriminos(i++);
//	if (argc == 1)
//		tetriminos = ft_parse_arg_to_binary(argv + 1);

	return (0);
}
