/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:03:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/22 08:17:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd_count_digit(size_t n, size_t *num)
{
	size_t	count;

	*num = n;
	count = 0;
	while ((n / 10) != 0)
	{
		n /= 10;
		*num = n;
		count++;
	}
	return (count);
}

size_t	ft_putnbr_fd_pow(size_t m)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 1;
	while (i < m)
	{
		result *= 10;
		i++;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	size_t	digit;
	size_t	disp_n;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n *= -1;
	}
	while (1)
	{
		digit = ft_putnbr_fd_count_digit((size_t)n, &disp_n);
		c = disp_n + '0';
		write(fd, &c, 1);
		if (digit == 0)
			return ;
		n -= disp_n * ft_putnbr_fd_pow(digit);
	}
}
