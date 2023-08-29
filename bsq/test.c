/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:58:33 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 17:53:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_input t_input;
typedef struct s_pos t_pos;
void	gen_int_map(t_input in, int ***int_map);
void	init_int_map(t_input in, int **int_map);
void	calc_int_map(t_input in, int **int_map)

char	**change_map(t_input in)
{
	int		**int_map;

	gen_int_map(in, &int_map)
	if (int_map != NULL)
	{
		init_int_map(in, int_map);
		calc_int_map(in, int_map);
	}
}

void	gen_int_map(t_input in, int ***int_map)
{
	int		**temp;
	int		i;

	temp = (int **)malloc(sizeof(int *) * (col + 1));
	if (temp != NULL)
	{
		i = 0;
		while (i < col + 1)
		{
			temp[i] = (int *)malloc(sizeof(int) * (row + 1));
			if (temp[i] == NULL)
			{
				temp = NULL;
				break ;
			}
			i++;
		}
	}
	*int_map = temp;
}

void	init_int_map(t_input in, int **int_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < in.col)
	{
		j = 0;
		while (j < in.row)
		{
			if (i == 0 || j == 0 || in.map[i][j] == in.obs)
				int_map[i][j] = 0;
			else
				int_map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int		min(int a, int b, int c)
{
	int		output;

	if (a < b)
		output = a;
	else
		output = b;
	if (c < output)
		output = c;
	return (output);
}

void	calc_int_map(t_input in, int **int_map)
{
	int		i;
	int		j;
	int		up;
	int		lu;
	int		lf;

	i = 1;
	while (i < in.col)
	{
		j = 1;
		while (j < in.row)
		{
			if (int_map[i][j] != 0)
			{
				up = int_map[i - 1][j];
				lu = int_map[i - 1][j - 1];
				lf = int_map[i][j - 1];
				int_map[i][j] = min(up, lu, lf) + 1;
			}
			j++;
		}
		i++;
	}
}

int	find_max_pos(t_input in, int **int_map)
{
	int		i;
	int		j;
	int		up;
	int		lu;
	int		lf;

	i = in.col - 1;
	while (0 < i)
	{
		j = 0;
		while (j < in.row)
		{
			if (int_map[i][j] != 0)
			{
				up = int_map[i - 1][j];
				lu = int_map[i - 1][j - 1];
				lf = int_map[i][j - 1];
				int_map[i][j] = min(up, lu, lf) + 1;
			}
			j++;
		}
		i++;
	}
}

struct s_input
{
	char	**map;
	int		row;//横
	int		col;//縦
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


int main(){

}
//40.ox
//{
//	"..o...........................",
//	"..............................",
//	"......o.....................o.",
//	"o.........................o...",
//	"........o.......o.............",
//	".o....o........o..o...o......."
//}


