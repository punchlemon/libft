/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:43:24 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 14:12:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	ft_check_bzero_child(char *b, char *ft_b, size_t copy_len)
{
	int		i;
	char	*p;

	p = "hello";
	memcpy(b, p, 5);
	memcpy(ft_b, p, 5);
	bzero(b, copy_len);
	ft_bzero(ft_b, copy_len);
	i = 0;
	while (i < 5)
	{
		if (b[i] != ft_b[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_bzero(void)
{
	int		i;
	char	b[5];
	char	ft_b[5];
	int		copy_len[2];

	copy_len[0] = 3;
	copy_len[1] = 5;
	i = 0;
	while (i < 2)
	{
		if (ft_check_bzero_child(b, ft_b, copy_len[i]) == 1)
			ft_checkprint(__func__, 1);
		i++;
	}
	ft_checkprint(__func__, 0);
}
