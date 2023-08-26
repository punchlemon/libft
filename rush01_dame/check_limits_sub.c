int	check_up(int **map, int size, int j)
{
	int	k;
	int	max;
	int	count;

	k = 0;
	max = 0;
	count = 0;
	while (k < size)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k++;
	}
	return (count);
}

int	check_down(int **map, int size, int j)
{
	int	k;
	int	max;
	int	count;

	k = size - 1;
	max = 0;
	count = 0;
	while (k >= 0)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k--;
	}
	return (count);
}

int	check_left(int **map, int size, int j)
{
	int	k;
	int	max;
	int	count;

	k = 0;
	max = 0;
	count = 0;
	while (k < size)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k++;
	}
	return (count);
}

int	check_right(int **map, int size, int j)
{
	int	k;
	int	max;
	int	count;

	k = size - 1;
	max = 0;
	count = 0;
	while (k >= 0)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k--;
	}
	return (count);
}

int	check_chosen(int **map, int *limits, int size, int *ij)
{
	int	count;

	count = 0;
	if (ij[0] == 0)
		count = check_up(map, size, ij[1]);
	else if (ij[0] == 1)
		count = check_down(map, size, ij[1]);
	else if (ij[0] == 2)
		count = check_left(map, size, ij[1]);
	else if (ij[0] == 3)
		count = check_right(map, size, ij[1]);
	return (count);
}