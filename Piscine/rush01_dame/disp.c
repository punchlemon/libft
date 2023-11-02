#include <unistd.h>

void	put_number(int n)
{
	write(1, &"0123456789"[n], 1);
}

void	disp(int **map, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (0 < j)
				write(1, " ", 1);
			put_number(map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
