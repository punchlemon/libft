/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:58:33 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 21:57:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_get_int_map(t_input *in, int ***m)
{
	int		**temp;
	int		i;

	temp = (int **)malloc(sizeof(int *) * (in->col + 1));
	if (temp != NULL)
	{
		i = 0;
		while (i < in->col)
		{
			temp[i] = (int *)malloc(sizeof(int) * (in->row));
			if (temp[i] == NULL)
			{
				temp = NULL;
				break ;
			}
			i++;
		}
	}
	*m = temp;
}

void	ft_init_int_map(t_input *in, int **m)
{
	int		i;
	int		j;

	i = 0;
	while (i < in->col)
	{
		j = 0;
		while (j < in->row)
		{
			if (in->map[i][j] == in->obs)
				m[i][j] = 0;
			else
				m[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	ft_calc_int_map(t_input *in, int **m, t_pos *max)
{
	int		i;
	int		j;

	i = -1;
	while (++i < in->col)
	{
		j = -1;
		while (++j < in->row)
		{
			if ((m[i][j] != 0) && (i == 0 || j == 0))
				m[i][j] = 1;
			else if (m[i][j] != 0)
			{
				m[i][j] = min(m[i - 1][j], m[i - 1][j - 1], m[i][j - 1])
					+ 1;
			}
			if (max->num < m[i][j])
			{
				max->x = j;
				max->y = i;
				max->num = m[i][j];
			}
		}
	}
}

void	ft_fill_in_map(t_input *in, t_pos *max)
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

void	ft_solve(t_input *in)
{
	int		**m;
	t_pos	max;

	max.x = 0;
	max.y = 0;
	max.num = 0;
	ft_get_int_map(in, &m);
	if (m != NULL)
	{
		ft_init_int_map(in, m);
		ft_calc_int_map(in, m, &max);
		ft_fill_in_map(in, &max);
	}
}

// #include <stdio.h>
// int main(){
// 	t_input test;
// 	t_input *p;
// 	char	*strs[] = {
// 		".",
// 	};
// 	p = &test;
// 	p->row = 1;
// 	p->col = 1;
// 	p->emp = '.';
// 	p->obs = 'o';
// 	p->ful = 'x';
// 	char	**temp = (char **)malloc(sizeof(char *) * (p->col + 1));
// 	int n = -1;
// 	while(++n < p->col)
// 	{
// 		temp[n] = (char *)malloc(sizeof(char) * (p->row + 1));
// 		int m = -1;
// 		while(++m < p->row)
// 			temp[n][m] = strs[n][m];
// 		temp[n][m] = '\0';
// 	}
// 	temp[n] = NULL;
// 	p->map = temp;

// 	int	i = -1;
// 	while (++i < p->col)
// 		printf("%s\n", p->map[i]);
// 	printf("%s\n", p->map[i]);

// 	ft_solve(p);
// 	printf("\n\n");

// 	i = -1;
// 	while (++i < p->col)
// 		printf("%s\n", p->map[i]);
// 	printf("%s\n", p->map[i]);
// }
