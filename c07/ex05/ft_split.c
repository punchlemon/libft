/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 10:36:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	check_charset(char c, char *charset)
{
	int	len;
	int	i;

	len = ftstrlen(charset);
	i = 0;
	while (i < len)
		if (c == charset[i])
			return (1);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_count;

	i = 0;
	while (i < str)
		{
		}
}
