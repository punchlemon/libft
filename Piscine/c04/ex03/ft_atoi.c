/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:07:48 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 11:46:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while ('0' <= *str && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (sign * num);
}
// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_atoi(" +a"));
// 	printf("%d\n", ft_atoi(" -2"));
// 	printf("%d\n", ft_atoi("  +--+--+-i"));
// 	printf("%d\n", ft_atoi(" -2147483648"));
// 	return 0;
// }
