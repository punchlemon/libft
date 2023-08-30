/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:41:30 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 08:12:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*c;

	i = 0;
	while (src[i])
		i++;
	src_len = i + 1;
	c = (char *)malloc(src_len);
	if (!c)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		c[i] = src[i];
		i++;
	}
	return (c);
}

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
			output[i].size = ft_strlen(av[i]);
			output[i].str = av[i];
			output[i].copy = ft_strdup(av[i]);
			i++;
		}
		output[i].size = 0;
		output[i].str = NULL;
		output[i].copy = NULL;
	}
	return (output);
}
