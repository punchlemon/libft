#include <stdlib.h>
int	factorial(int size);

void	free_map(int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
}

void	free_limits(int **limits)
{
	int	i;

	i = 0;
	while (i < 4)
		free(limits[i++]);
	free(limits);
}

void	free_dic(int **dic, int size)
{
	int	i;

	i = 0;
	while (i < factorial(size))
		free(dic[i++]);
	free(dic);
}

void	execute_free(int **map, int **limits, int **dic, int size)
{
	free_map(map, size);
	free_limits(limits);
	free_dic(dic, size);
}
