int	check_chosen(int **map, int *limits, int size, int *ij);

int	check_line(int **map, int size, int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[row][i] == value || map[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(int **map, int **limits, int size)
{
	int	ij[2];

	ij[0] = 0;
	while (ij[0] < 4)
	{
		ij[1] = 0;
		while (ij[1] < size)
		{
			if (limits[ij[0]][ij[1]] != check_chosen(map, limits, size, ij))
				return (0);
			ij[1]++;
		}
		ij[0]++;
	}
	return (1);
}
