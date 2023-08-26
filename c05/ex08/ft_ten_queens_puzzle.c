/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:19:19 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 08:28:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	

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

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_ten_queens_puzzle());
// }