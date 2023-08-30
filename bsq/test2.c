
#include <stdlib.h>
#include <unistd.h>

struct s_input
{
	char	**map;
	int		row;
	int		col;
	char	emp;
	char	obs;
	char	ful;
};

struct s_pos
{
	int	x;
	int	y;
	int	num;
};

typedef struct s_input	t_input;
typedef struct s_pos	t_pos;
void	gen_int_map(t_input *in, int ***int_map);
void	init_int_map(t_input *in, int **int_map);
int		min(int a, int b, int c);
void	calc_int_map(t_input *in, int **int_map);
void	find_max_pos(t_input *in, int **int_map, t_pos *max);
void	fill_in_map(t_input *in, t_pos *max);

void	calc_int_map(t_input *in, int **m)
{
	int		i;
	int		j;

	i = 0;
	while (i < in->col)
	{
		j = 0;
		while (j < in->row)
		{
			if (m[i][j] != 0)
			{
				if (i == 0 || j == 0)
					m[i][j] = 1;
				else
				{
					m[i][j] = min(m[i - 1][j], m[i - 1][j - 1], m[i][j - 1])
						+ 1;
				}
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void	find_max_pos(t_input *in, int **int_map, t_pos *max)
{
	int	i;
	int	j;

	i = 0;
	while (i < in->col)
	{
		j = 0;
		while (j < in->row)
		{
			if (max->num < int_map[i][j])
			{
				max->x = j;
				max->y = i;
				max->num = int_map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	fill_in_map(t_input *in, t_pos *max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max->num)
	{
		j = 0;
		while (j < max->num)
		{
			in->map[max->y - i][max->x - j] = in->ful;
			j++;
		}
		i++;
	}
}
