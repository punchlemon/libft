/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:27:00 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 10:03:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_recursive_power(0, 3));
// 	printf("%d\n", ft_recursive_power(0, 0));
// 	printf("%d\n", ft_recursive_power(0, -3));
// 	printf("%d\n", ft_recursive_power(3, 3));
// 	printf("%d\n", ft_recursive_power(3, 0));
// 	printf("%d\n", ft_recursive_power(3, -3));
// 	printf("%d\n", ft_recursive_power(-3, 3));
// 	printf("%d\n", ft_recursive_power(-3, 0));
// 	printf("%d\n", ft_recursive_power(-3, -3));
// }
