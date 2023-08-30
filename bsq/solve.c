/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:58:33 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 21:15:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	solve(t_input *in)
{
	int		**int_map;
	t_pos	max;

	max.x = 0;
	max.y = 0;
	max.num = 0;
	gen_int_map(in, &int_map);
	if (int_map != NULL)
	{
		init_int_map(in, int_map);
		calc_int_map(in, int_map);
		find_max_pos(in, int_map, &max);
		fill_in_map(in, &max);
	}
}

void	gen_int_map(t_input *in, int ***int_map)
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
	*int_map = temp;
}

void	init_int_map(t_input *in, int **int_map)
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
				int_map[i][j] = 0;
			else
				int_map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	min(int a, int b, int c)
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

// #include <stdio.h>
// int main(){
// 	t_input test;
// 	t_input *p;
// 	//char	*strs[] = {
// 	//	".",
// 	//};
// 	//p = &test;
// 	//p->row = 1;
// 	//p->col = 1;
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

// 	change_map(p);
// 	printf("\n\n");

// 	i = -1;
// 	while (++i < p->col)
// 		printf("%s\n", p->map[i]);
// 	printf("%s\n", p->map[i]);
// }