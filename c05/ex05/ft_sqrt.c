/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:46:56 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 08:28:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_sqrt(3));
// 	printf("%d\n", ft_sqrt(4));
// 	printf("%d\n", ft_sqrt(100));
// 	printf("%d\n", ft_sqrt(0));
// 	printf("%d\n", ft_sqrt(-9));
// 	printf("%d\n", ft_sqrt(2147483647));
// 	return 0;
// }
