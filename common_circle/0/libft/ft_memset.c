/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:58:28 by retanaka          #+#    #+#             */
/*   Updated: 2023/10/11 06:55:29 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *buf, int ch, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)buf;
	while (i < len)
		p[i++] = ch;
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	char b[10];
// 	char ft_b[10];
// 	int len = 10;
// 	ft_memset(ft_b, '0', len);
// 	memset(b, '0', len);
// 	printf("ft:%s\n", ft_b);
// 	printf("me:%s\n", b);
// }
