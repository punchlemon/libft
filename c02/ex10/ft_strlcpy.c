/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:21:09 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/22 20:19:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	while (src[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && i < src_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
// #include <unistd.h>
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char dest[] = "hello";
// 	char src[] = "world";
// 	printf("%d", (int)ft_strlcpy(dest, src, 7));
// 	write(1, dest, 5);
// 	write(1, "\n", 1);
// 	char dest2[] = "hello";
// 	char src2[] = "world";
// 	printf("%d", (int)strlcpy(dest2, src2, 7));
// 	write(1, dest2, 5);
// }
