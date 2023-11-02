/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:28 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/24 09:47:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src && 0 < nb)
	{
		*ptr = *src;
		ptr++;
		src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main(){
// 	int size = 1;
// 	char s1[100] = "hello";
// 	char s2[] = "world";
// 	printf("%s\n", strncat(s1, s2, size));
// 	char s3[100] = "hello";
// 	char s4[] = "world";
// 	printf("%s\n", ft_strncat(s3, s4, size));
// }