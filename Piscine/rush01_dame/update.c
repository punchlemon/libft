int		check_limits(int **map, int **limits, int size);
int		*change_chosen_pattern(int **dic_index, int **limits, int size, int i);
void	insert_pattern(int **map, int *pattern, int i, int size);

int	update(int **map, int **limits, int size, int **dic_index)
{
	int	i;
	int	change_row;
	int	index;
	int	*index_status;
	int	pattern;

	while (!check_limits(map, limits, size))
	{
		index_status = change_chosen_pattern(dic_index, limits, size, 0);
		if (change_row == -1)
			return (0);
		else
		{
			i = 0;
			while (i <= change_row)
			{
				index = (limits[2][i] - 1) * size + (limits[3][i] - 1);
				pattern = dic_index[index] + index_status[i];
				insert_pattern(map, pattern, i, size);
				i++;
			}
		}
	}
	return (1);
}
