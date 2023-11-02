/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:56:03 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 10:05:07 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;
	long long	j;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (!(nb % 2) || !(nb % 3))
		return (0);
	i = 1;
	while ((6 * i - 1) * (6 * i - 1) <= nb)
	{
		j = 6 * i - 1;
		if (!(nb % j))
			return (0);
		j = 6 * i + 1;
		if (!(nb % j))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_is_prime(2));
// 	printf("%d\n", ft_is_prime(3));
// 	printf("%d\n", ft_is_prime(4));
// 	printf("%d\n", ft_is_prime(5));
// 	printf("%d\n", ft_is_prime(6));
// 	printf("%d\n", ft_is_prime(2147483647));
// 	return 0;
// }
