/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:53:40 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			num;
	long long	result;

	sign = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] - '+') / 2;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		num = str[i] - '0';
		if ((result > 922337203685477580) || (result == 922337203685477580
				&& ((sign == 1 && num > 8) || (sign == 0 && num > 7))))
			return (sign - 1);
		result *= 10;
		result += num;
		i++;
	}
	if (sign == 1 && 0 < result)
		result *= -1;
	return (result);
}
