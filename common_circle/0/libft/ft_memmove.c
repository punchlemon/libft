/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:15:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/02 07:33:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;
	int	dif;
	int	end;

	if (dst < src)
	{
		i = 0;
		dif = 1;
		end = n;
	}
	else
	{
		i = n;
		dif = -1;
		end = -1;
	}
	while (i != end)
	{
		dst[i] = src[i];
		i += dif;
	}
	return (dst);
}
