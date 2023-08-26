/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:17:29 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/14 16:48:05 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nums(int a, int b)
{
	char	c;

	if (a != 0 || b != 1)
	{
		write(1, ", ", 2);
	}
	c = a / 10 + '0';
	write(1, &c, 1);
	c = a % 10 + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = b / 10 + '0';
	write(1, &c, 1);
	c = b % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			if (a != b)
				write_nums(a, b);
			b++;
		}
		a++;
	}
}
