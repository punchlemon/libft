/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:15:10 by retanaka          #+#    #+#             */
/*   Updated: 2023/10/11 08:30:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	int	dif;
	int	end;

	if (dst < src)
	{
		i = 0;
		dif = 1;
		end = len;
	}
	else
	{
		i = len;
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

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	int len = 0;
	char f[] = "0123456789";
	ft_memcpy(f, NULL, len);
	for(int i = 0; i < 10; i++){
		write(1, f + i, 1);
	}
}
