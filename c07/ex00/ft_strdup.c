/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:06:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 07:18:14 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	i = 0;
	while (src[i])
		i++;
	c = (char *)malloc(i++);
	if (!c)
		return (NULL);
	while (i--)
		c[i] = src[i];
	return (c);
}

//#include <stdio.h>
//int main()
//{
//	char *c = ft_strdup("hello");
//	if (c)
//	{
//		printf("%s\n", c);
//		free(c);
//	}
//}
