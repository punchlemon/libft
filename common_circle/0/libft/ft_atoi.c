/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:31:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/15 16:51:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign = 1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && 0 < result)
			result *= -1;
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
