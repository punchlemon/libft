int	look_from_left(int *pattern, int size);
int	look_from_right(int *pattern, int size);

void	set_left_right(int **dic, int pattern_count, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < pattern_count)
	{
		dic[i][0] = look_from_left(dic[i], size);
		dic[i][1] = look_from_right(dic[i], size);
		i++;
	}
}

int	look_from_left(int *pattern, int size)
{
	int	i;
	int	max;
	int	count;

	i = 2;
	max = 0;
	count = 0;
	while (i < size + 2)
	{
		if (pattern[i] > max)
		{
			max = pattern[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	look_from_right(int *pattern, int size)
{
	int	i;
	int	max;
	int	count;

	i = (size + 2) - 1;
	max = 0;
	count = 0;
	while (i >= 2)
	{
		if (pattern[i] > max)
		{
			max = pattern[i];
			count++;
		}
		i--;
	}
	return (count);
}
