/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:53:04 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 23:12:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_null(char **str) 
{
	if (str[0] == NULL || str[1] == NULL)
		return (1);
	else
		return (0);
}

int	ft_check_first_line(char *str, int num_len)
{
	int	i;

	if (num_len <= 0)
		return (1);
	if (str[0] == '0')
		return (1);
	i = 0;
	while (i < num_len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (str[i] == str[i + 1] || str[i + 1] == str[i + 2]
		|| str[i + 2] == str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_num_of_line(char *str, int num_len, int *num_on_line)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (i < num_len)
	{	
		result *= 10;
		result += (str[i] - '0');
		i++;
		if (result > 2147483647)
			return (1);
	}
	*num_on_line = result;
	return (0);
}

int	ft_checker(char **str, char empty, char obs, int num_of_line)
{
	int	i;
	int	j;
	int	num_char_per_line;

	i = 1;
	j = 0;
	num_char_per_line = ft_strlen(str[1]);
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != num_char_per_line)
			return (1);
		while (str[i][j] != '\0')
		{
			if (str[i][j] != empty && str[i][j] != obs)
				return (1);
			j++;
		}
		i++;
	}
	if (num_of_line != (i - 1))
		return (1);
	return (0);
}

int	ft_check_map(char **str)
{
	int	num_len;
	int	num_of_line;

	num_len = ft_strlen(str[0]) - 3;
	if (ft_check_first_line(str[0], num_len))
		return (1);
	if (ft_get_num_of_line(str[0], num_len, &num_of_line))
		return (1);
	if (ft_checker(str, str[0][num_len - 3], str[0][num_len - 2], num_of_line))
		return (1);
	return (0);
}
