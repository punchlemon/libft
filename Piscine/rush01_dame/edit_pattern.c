int	factorial(int size);

void	insert_pattern(int **map, int *pattern, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		map[j][i] = pattern[j + 2];
		j++;
	}
}

void	init_pattern(int **map, int **dic, int **limits, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < factorial(size))
		{
			if ((dic[j][0] == limits[0][j])
				&& (dic[j][1] == limits[1][j]))
			{
				insert_map(map, dic[j], j, size);
			}
			else
				j++;
		}
		i++;
	}
}

int	*change_chosen_pattern(int **dic_index, int **limits, int size, int i)
{
	static int	index_status[9];
	int			index;
	int			ret[2];

	if (i == size)
		return ((void *)0);
	index = (limits[2][i] - 1) * size + (limits[3][i] - 1);
	while (1)
	{
		if (dic_index[index] + index_status[i] + 1
			< dic_index[index + 1])
		{
			index_status[i]++;
			return (index_status);
		}
		else
		{
			index_status[i] = 0;
			return (change_chosen_pattern(dic_index, limits, size, i + 1));
		}
	}
}
