/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:48:51 by rnameki           #+#    #+#             */
/*   Updated: 2023/08/27 22:15:27 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	judge_scale(int nb)
{
	int	scale;

	scale = 0;
	if (nb >= 1000)
		scale++;
	if (nb >= 1000000)
		scale++;
	if (nb >= 1000000000)
		scale++;
	return (scale);
}

void	put_two_dig(long nb, char *filename)
{
	long	n;

	if (nb % 100 >= 20)
	{
		n = (((nb % 100) / 10) * 10);
		write_string(n, filename);
		write(1, " ", 1);
	}
	if (nb % 100 >= 10 && nb % 100 < 20)
	{
		n = (nb % 100);
		write_string(n, filename);
		write(1, " ", 1);
	}
	if ((nb % 100 < 10 || nb % 100 >= 20) && nb % 10 > 0)
	{
		n = (nb % 10);
		write_string(n, filename);
		write(1, " ", 1);
	}
}

void	put_depth(int nb, int depth, char *filename)
{
	if (nb % 1000 > 0)
	{
		if (depth == 3)
		{
			write_string(1000000000, filename);
			write(1, " ", 1);
		}
		if (depth == 2)
		{
			write_string(1000000, filename);
			write(1, " ", 1);
		}
		if (depth == 1)
		{
			write_string(1000, filename);
			write(1, " ", 1);
		}
	}
}

void	recursive_split(long nb, int scale, int depth, char *filename)
{
	long	n;

	if (depth != scale + 1)
		recursive_split((nb / 1000), scale, depth + 1, filename);
	if (nb % 1000 >= 100)
	{
		n = ((nb % 1000) / 100);
		write_string(n, filename);
		write(1, " ", 1);
		write_string(100, filename);
		write(1, " ", 1);
	}
	put_two_dig(nb, filename);
	put_depth(nb, depth, filename);
}

void	split_number(long nb, char *filename)
{
	int		scale;

	if (nb == 0)
	{
		write_string(0, filename);
		return ;
	}
	scale = judge_scale(nb);
	recursive_split(nb, scale, 0, filename);
}

// int	main(void)
// {
// 	split_number(674670000000);
// 	return (0);
// }
