/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:08:39 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/12 15:13:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *nums, int n)
{
	char	c;

	c = '0';
	while (c < (n + '0'))
	{
		nums[c - '0'] = c;
		c++;
	}
	write(1, nums, n);
}

int	check_digit(char *nums, int n)
{
	int	i;

	i = n - 1;
	while (0 <= i)
	{
		if ((nums[i] + (n - 1) - i) == '9')
			i--;
		else
			return (i);
	}
	return (n);
}

void	count_up(char *nums, int n, int i)
{
	int	a;

	nums[i]++;
	a = i + 1;
	while (a < n)
	{
		nums[a] = nums[a - 1] + 1;
		a++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];
	int		i;

	init(nums, n);
	while (1)
	{
		i = check_digit(nums, n);
		if (i != n)
		{
			write(1, ", ", 2);
			count_up(nums, n, i);
			write(1, nums, n);
		}
		else
			break ;
	}
}
