/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strlcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:26:03 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include <unistd.h>

void	ft_check_strlcpy_init(char p1[2][10], char p2[2][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 10)
		{
			p1[i][j] = j;
			p2[i][j] = j;
			j++;
		}
		i++;
	}
}

void	ft_check_strlcpy_set(char *p1, char *p2, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		p1[i] = s[i];
		p2[i] = s[i];
		i++;
	}
}

int	ft_check_strlcpy_result(int a, int ft_a, char *dst, char *ft_dst)
{
	int	i;

	if (a != ft_a)
		return (1);
	i = 0;
	while (i < 10)
	{
		if (dst[i] != ft_dst[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_strlcpy(void)
{
	int		r;
	char	dst[2][10];
	char	src[2][10];
	char	ft_dst[2][10];
	char	ft_src[2][10];

	r = 0;
	ft_check_strlcpy_init(dst, ft_dst);
	ft_check_strlcpy_set(dst[0], ft_dst[0], "hello");
	ft_check_strlcpy_set(src[0], ft_src[0], "world ");
	ft_check_strlcpy_set(dst[1], ft_dst[1], "");
	ft_check_strlcpy_set(src[1], ft_src[1], "world");
	r += ft_check_strlcpy_result(strlcpy(dst[0], src[0], 6),
			ft_strlcpy(ft_dst[0], ft_src[0], 6), dst[0], ft_dst[0]);
	r += ft_check_strlcpy_result(strlcpy(dst[1], src[1], 3),
			ft_strlcpy(ft_dst[1], ft_src[1], 3), dst[1], ft_dst[1]);
	ft_checkprint(__func__, r);
}
