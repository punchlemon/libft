/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:15:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/18 10:37:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	int		dif;
	int		end;
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	dif = 1;
	end = n;
	if (s <= d)
	{
		i = n;
		dif = -1;
		end = -1;
	}
	while (i != end)
	{
		d[i] = s[i];
		i += dif;
	}
	return (dst);
}
