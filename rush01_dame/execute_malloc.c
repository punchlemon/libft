#include <stdlib.h>
int	factorial(int size);

void	make_map(int ***map, int size)
{
	int	i;
	int	j;
	int	i_end;
	int	j_end;

	i_end = size;
	j_end = size;
	*map = (int **)malloc(sizeof(int *) * i_end);
	i = 0;
	while (i < i_end)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * j_end);
		j = 0;
		while (j < j_end)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	make_limits(int ***limits, int size)
{
	int	i;
	int	j;
	int	i_end;
	int	j_end;

	i_end = 4;
	j_end = size;
	*limits = (int **)malloc(sizeof(int *) * i_end);
	i = 0;
	while (i < i_end)
	{
		(*limits)[i] = (int *)malloc(sizeof(int) * j_end);
		j = 0;
		while (j < j_end)
		{
			limits[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	make_dic(int ***dic, int size)
{
	int	i;
	int	j;
	int	i_end;
	int	j_end;

	i_end = factorial(size);
	j_end = size + 2;
	*dic = (int **)malloc(sizeof(int *) * i_end);
	i = 0;
	while (i < i_end)
	{
		(*dic)[i] = (int *)malloc(sizeof(int) * j_end);
		j = 0;
		while (j < j_end)
		{
			dic[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	execute_malloc(int ***map, int ***limits, int ***dic, int size)
{
	make_map(map, size);
	make_limits(limits, size);
	make_dic(dic, size);
}
