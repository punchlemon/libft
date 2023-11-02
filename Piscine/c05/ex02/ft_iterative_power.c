/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:25:56 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 12:06:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;

	if (power < 0)
		ret = 0;
	else
		ret = 1;
	while (power-- > 0)
		ret *= nb;
	return (ret);
}

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_iterative_power(0, 3));
// 	printf("%d\n", ft_iterative_power(0, 0));
// 	printf("%d\n", ft_iterative_power(0, -3));
// 	printf("%d\n", ft_iterative_power(3, 3));
// 	printf("%d\n", ft_iterative_power(3, 0));
// 	printf("%d\n", ft_iterative_power(3, -3));
// 	printf("%d\n", ft_iterative_power(-3, 3));
// 	printf("%d\n", ft_iterative_power(-3, 0));
// 	printf("%d\n", ft_iterative_power(-3, -3));
// }
