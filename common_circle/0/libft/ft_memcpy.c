/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:11:40 by retanaka          #+#    #+#             */
/*   Updated: 2023/10/11 08:29:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// int main(){
// 	int len = 0;
// 	char f[] = "0123456789";
// 	ft_memcpy(f, NULL, len);
// 	for(int i = 0; i < 10; i++){
// 		write(1, f + i, 1);
// 	}
// }
