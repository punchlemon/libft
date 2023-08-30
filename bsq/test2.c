/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:58:53 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 15:59:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

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
