/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:40:05 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 23:25:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_newline_character(char *str)
{
	int	i;

	if (str[0] == '\n')
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
