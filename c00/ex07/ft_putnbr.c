/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:03:12 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/24 15:48:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long long	num;
	char		c;

	num = nb;
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
			ft_putnbr((int)num);
		}
		else if (num == 0)
			write(1, "0", 1);
		else
		{
			c = num % 10 + '0';
			if (num / 10 != 0)
				ft_putnbr((int)(num / 10));
			write(1, &c, 1);
		}
	}
}

//int	main(void)
//{
//	ft_putnbr(-2147483648);
//	write(1, "\n", 1);
//	ft_putnbr(42);
//	write(1, "\n", 1);
//	ft_putnbr(-2);
//	write(1, "\n", 1);
//	ft_putnbr(0);
//	write(1, "\n", 1);
//}
