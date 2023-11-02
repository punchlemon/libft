/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:26:02 by adaichi           #+#    #+#             */
/*   Updated: 2023/08/27 22:26:25 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_two_dig(long nb, char *filename)
{
	long	n;

	if (nb % 100 >= 20)
	{
		n = (((nb % 100) / 10) * 10);
		if (find_nbr(n, filename) == -1)
			return (-1);
	}
	if (nb % 100 >= 10 && nb % 100 < 20)
	{
		n = (nb % 100);
		if (find_nbr(n, filename) == -1)
			return (-1);
	}
	if ((nb % 100 < 10 || nb % 100 >= 20) && nb % 10 > 0)
	{
		n = (nb % 10);
		if (find_nbr(n, filename) == -1)
			return (-1);
	}
	return (0);
}

int	check_depth(int nb, int depth, char *filename)
{
	if (nb % 1000 > 0)
	{
		if (depth == 3 && find_nbr(1000000000, filename) == -1)
			return (-1);
		if (depth == 2 && find_nbr(1000000, filename) == -1)
			return (-1);
		if (depth == 1 && find_nbr(1000, filename) == -1)
			return (-1);
	}
	return (0);
}

int	recursive_check(long nb, int scale, int depth, char *filename)
{
	long	n;

	if (depth != scale + 1)
		recursive_check((nb / 1000), scale, depth + 1, filename);
	if (nb % 1000 >= 100)
	{
		n = ((nb % 1000) / 100);
		if (find_nbr(n, filename) == -1)
			return (-1);
		if (find_nbr(100, filename) == -1)
			return (-1);
	}
	if (check_two_dig(nb, filename) == -1)
		return (-1);
	if (check_depth(nb, depth, filename) == -1)
		return (-1);
	return (0);
}

int	check_number(long nb, char *filename)
{
	int	scale;

	if (nb == 0)
	{
		if (find_nbr(0, filename) == -1)
			return (-1);
	}
	scale = judge_scale(nb);
	return (recursive_check(nb, scale, 0, filename));
}
