int		error(void);
int		process_input(char *str, int **array, int *size);
void	execute_malloc(int ***map, int ***limits, int ***dic, int size);
void	init_pattern(int **map, int **dic, int **limits, int size);
void	make_dic_index(int ***dic_index, int **dic, int size);
int		update(int **map, int **limits, int size, int **dic_index);
void	disp(int **map, int size);
void	execute_free(int **map, int **limits, int **dic, int size);

int	main(int argc, char *argv[])
{
	int	**dic;
	int	**map;
	int	**limits;
	int	**dic_index;
	int	size;

	execute_malloc(map, limits, dic, size);
	if (argc == 2 && process_input(argv[1], limits, &size))
	{
		init_pattern(map, dic, limits, size);
		//あっきーの関数
		make_dic_index(&dic_index, dic, size);
		//あっきーの関数
		if(update(map, limits, size, dic_index))
			disp(map, size);
		else
			error();
	}
	else
		error();
	execute_free(map, limits, dic, size);
	return (0);
}
