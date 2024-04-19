/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:20 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 15:04:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_memcpy_init(char *p)
{
	int	i;

	i = 0;
	while (i < 30)
	{
		p[i] = i + '0';
		i++;
	}
}

int	ft_check_memcpy_result(char *p, char *ft_p)
{
	int	i;

	i = 0;
	while (i < 30)
	{
		if (p[i] != ft_p[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_memcpy(void)
{
	char	p[30];
	char	ft_p[30];

	ft_check_memcpy_init(p);
	ft_check_memcpy_init(ft_p);
	memcpy(p, p + 10, 15);
	ft_memcpy(ft_p, ft_p + 10, 15);
	ft_checkprint(__func__, ft_check_memcpy_result(p, ft_p));
}
