#include <stdlib.h>
#include <unistd.h>

int	get_size(char *str)
{
	int size;
	
	size = 0;
	while (*str)
	{
		if (*str == ' ')
			size++;
		str++;
	}
	return ((size + 1) / 4);
}

void	print_map(int **map, int size)
{
	int		i = 0, j;
	char	c;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		check_line(int **map, int size, int row, int col, int value)
{
	int i = 0;

	while (i < size)
	{
		if (map[row][i] == value || map[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}

// check_constraints

static int check_up(int **map, int size, int j)
{
	int k = 0, max = 0, count = 0;
	while (k < size)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k++;
	}
	return count;
}

static int check_down(int **map, int size, int j)
{
	int k = size - 1, max = 0, count = 0;
	while (k >= 0)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k--;
	}
	return count;
}

static int check_left(int **map, int size, int j)
{
	int k = 0, max = 0, count = 0;
	while (k < size)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k++;
	}
	return count;
}

static int check_right(int **map, int size, int j)
{
	int k = size - 1, max = 0, count = 0;
	while (k >= 0)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k--;
	}
	return count;
}

int	check_constraints(int **map, int *constraints, int size)
{
	int i = 0, j;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			int count = 0;
			if (i == 0)
				count = check_up(map, size, j);
			else if (i == 1)
				count = check_down(map, size, j);
			else if (i == 2)
				count = check_left(map, size, j);
			else if (i == 3)
				count = check_right(map, size, j);

			if (constraints[i * size + j] != count)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//

int		solve(int **map, int *constraints, int size, int pos)
{
	if (pos == size * size)
		return (check_constraints(map, constraints, size));

	int x = pos / size;
	int y = pos % size;
	int value = 1;

	while (value <= size)
	{
		if (check_line(map, size, x, y, value))
		{
			map[x][y] = value;
			if (solve(map, constraints, size, pos + 1))
				return (1);
			map[x][y] = 0;
		}
		value++;
	}
	return (0);
}

// main

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	int size = get_size(argv[1]);
	if (size < 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	int **map = (int **)malloc(size * sizeof(int *));
	int i = 0;
	while (i < size)
	{
		map[i] = (int *)malloc(size * sizeof(int));
		int j = 0;
		while (j < size)
		{
			map[i][j] = 0; // 明示的に0で初期化
			j++;
		}
		i++;
	}

	int	constraints[4 * size];
	int k = 0;

	while (k < 4 * size)
	{
		if (argv[1][k * 2] < '1' || argv[1][k * 2] > '0' + size ||
			(k < 4 * size - 1 && argv[1][k * 2 + 1] != ' '))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		constraints[k] = argv[1][k * 2] - '0';
		k++;
	}

	if (solve(map, constraints, size, 0))
		print_map(map, size);
	else
		write(1, "Error\n", 6);

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);

	return (0);
}
