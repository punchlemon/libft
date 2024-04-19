/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:15:38 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 13:42:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	ft_check_memset_child(char *b, char *ft_b, char c, size_t copy_len)
{
	int		i;
	char	*p;

	p = "hello";
	memcpy(b, p, 5);
	memcpy(ft_b, p, 5);
	memset(b, c, copy_len);
	ft_memset(ft_b, c, copy_len);
	i = 0;
	while (i < 5)
	{
		if (b[i] != ft_b[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_memset(void)
{
	int		i;
	char	b[5];
	char	ft_b[5];
	int		copy_len[4];
	int		c[4];

	copy_len[0] = 3;
	copy_len[1] = 5;
	copy_len[2] = 3;
	copy_len[3] = 3;
	c[0] = 'c';
	c[1] = 'c';
	c[2] = -2147483648;
	c[3] = 2147483647;
	i = 0;
	while (i < 4)
	{
		if (ft_check_memset_child(b, ft_b, c[i], copy_len[i]) == 1)
			ft_checkprint(__func__, 1);
		i++;
	}
	ft_checkprint(__func__, 0);
}
