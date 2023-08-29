/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:41:30 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 12:34:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*output;

	output = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (output != NULL)
	{
		i = 0;
		while (i < ac)
		{
			output[i].size = str_len(av[i]);
			output[i].str = av[i];
			output[i].copy = strdup(av[i]);
			i++;
		}
		output[i].size = 0;
		output[i].str = NULL;
		output[i].copy = NULL;
	}
	return (output);
}
