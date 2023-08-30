/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:06:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 08:33:55 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*c;

	i = 0;
	while (src[i])
		i++;
	src_len = i + 1;
	c = (char *)malloc(src_len);
	if (!c)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		c[i] = src[i];
		i++;
	}
	return (c);
}

// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
// 	char *c = ft_strdup("hello");
// 	if (c)
// 	{
// 		int i = 0;
// 		while(c[i])
// 			write(1, &c[i++], 1);
// 		write(1, &c[i], 1);
// 		free(c);
// 	}
// }
