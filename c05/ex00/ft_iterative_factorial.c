/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:07:05 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/16 18:24:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		ret = 0;
	else
	{
		ret = 1;
		while (nb)
			ret *= nb--;
	}
	return (ret);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_iterative_factorial(5));
// 	printf("%d\n", ft_iterative_factorial(0));
// 	printf("%d\n", ft_iterative_factorial(-5));
// }
