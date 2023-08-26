void	get_size(char *str, int *size)
{
	*size = 0;
	while (*str)
	{
		if (*str == ' ')
			(*size)++;
		str++;
	}
	*size = (*size + 1) / 4;
}

int	check_str_form(char *str, int size)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (((i % 2 == 0) && (*str < '1' || size + '0' < *str))
			|| ((i % 2 == 1) && (*str != ' ')))
			return (0);
		str++;
	}
	return (1);
}

void	assign_limits(char *str, int size, int **limits)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		while (j < size)
		{
			limits[i][j] = str[i * size + j];
			j++;
		}
		i++;
	}
}

int	process_input(char *str, int **limits, int *size)
{
	get_size(str, size);
	if (check_str_form(str, *size))
	{
		assign_limits(str, *size, limits);
		return (1);
	}
	return (0);
}
