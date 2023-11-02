/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:19:19 by retanaka          #+#    #+#             */
/*   Updated: 2023/09/06 21:46:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 10

int	ft_ten_queens_puzzle(void)
{
	static char	c[11];
	static int	d;
	int			n;

	c[10] = '\n';
	n = 0;
	while (n != -1)
	{
		if (++c[d] < '0')
			c[d] = '0';
		if ('9' < c[d])
			return (677 + (c[d--] = '0' - 1));
		n = d;
		while (n-- && c[n] != c[d]
			&& (c[n] + d - n) != c[d] && (c[n] + n - d) != c[d]);
	}
	if (d-- == 9)
		return (write(1, c, 11));
	else
	{
		d += 2;
		c[d] = '0' - 1;
		ft_ten_queens_puzzle();
		return (ft_ten_queens_puzzle());
	}
}

int	ft_ten_queens_puzzle2(void)
{
	static char	c[11];
	static int	d;
	int			n;
	static int	cnt;

	c[10] = '\n';
	n = 0;
	while (n != -1)
	{
		if (++c[d] < '0')
			c[d] = '0';
		if ('9' < c[d])
			return (cnt - 47 + (c[d--] = '0' - 1));
		n = d;
		while (n-- && c[n] != c[d]
			&& (c[n] + d - n) != c[d] && (c[n] + n - d) != c[d]);
	}
	if (d-- == 9 && cnt++)
		return (write(1, c, 11));
	else
	{
		d += 2;
		c[d] = '0' - 1;
		ft_ten_queens_puzzle2();
		return (ft_ten_queens_puzzle2());
	}
}

int	ft_ten_queens_puzzle3(void)
{
	static char	z[N + 1];
	static int	x;
	int			i;
	static int	cnt;

	z[N] = '\n';
	if (x == N && cnt++ && x--)
		write(1, z, N + 1);
	else
	{
		z[x] = '0' - 1;
		while (++z[x] < '0' + N || (!(x--)))
		{
			i = -1;
			while (++i < x && !(z[i] == z[x] || z[i] - z[x] == i - x
					|| z[i] - z[x] == - (i - x)));
			if (i == x && ++x)
				ft_ten_queens_puzzle3();
		}
	}
	return (cnt);
}

 #include <stdio.h>
 int main(){
 	printf("%d\n", ft_ten_queens_puzzle2());
 }

// int	ft_ten_queens_puzzle2(void)
// {
// 	static char	c[N + 1];
// 	static int	d;
// 	int			i;
// 	static int	cnt;

// 	c[N] = '\n';
// 	i = 0;
// 	while (i != -1)
// 	{
// 		if (++c[d] < '0')
// 			c[d] = '0';
// 		if ('9' < c[d])
// 			return ((c[d--] = '0' - 1));
// 		i = d;
// 		while (i-- && c[i] != c[d]
// 			&& (c[i] + d - i) != c[d] && (c[i] + i - d) != c[d]);
// 	}
// 	if (d++ != N - 1)
// 		ft_ten_queens_puzzle2();
// 	else if (d == N - 1 && cnt++)
// 		write(1, c, N + 1);
// 	return (cnt);
// }