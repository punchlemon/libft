/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:40:05 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 21:33:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_newline_character(char *str)
{
	int	i;

	if (str[0] != '\n')
		return (1);
	i = 1;
	while (str[i] != '\0')
	{
		if ((str[i - 1] == '\n' && str[i] == '\n'))
			return (1);
		i++;
	}
	if (str[i - 1] != '\n')
		return (1);
	else
		return (0);
}

int	ft_check_null(char **str)
{
	if (str[0] == NULL || str[1] == NULL)
		return (1);
	else
		return (0);
}

// int	ft_get_num_of_line(char *str)
// {
// 	int	i;

// 	len = ft_strlen(str);
// 	i = 1;
// 	while (i < (len - 3))
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (1);
// 		i++;
// 	}
	
// }


int	ft_check_first_line(char *str)
{
	int	num_len;
	int	i;

	num_len = ft_strlen(str[0]) - 3;
	if (num_len <= 0)
		return (1);
	i = 0;
	while (i < num_len)
	{
		
		i++;
	}
}

int ft_check_map(char **str)
{
	// int	num_len;

	// num_len = ft_strlen(str[0]) - 3;
	// if (num_len <= 0)
	// 	return (1);



	ft_check_first_line(str[0]);

	if (str[0][0] == '0')
		return (1);
	
}