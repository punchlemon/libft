/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:51 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/24 10:31:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	t_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	t_len = d_len + s_len;
	if (size <= d_len)
		return (s_len + size);
	while (*dest)
		dest++;
	while (*src && (d_len + 1) < size)
	{
		*dest = *src;
		dest++;
		src++;
		d_len++;
	}
	*dest = '\0';
	return (t_len);
}

#include <stdio.h>
#include <string.h>
int main(){
	// size < dest
	int size = 3;
	char s1[20] = "hello";
	char s2[] = "world!!";
	printf("%lu,", (unsigned long)ft_strlcat(s1, s2, size));
	printf("%s\n", s1);
	char s3[20] = "hello";
	char s4[] = "world!!";
	printf("%lu,", strlcat(s3, s4, size));
	printf("%s\n", s3);
	// dest <= size < dest + src
	size = 11;
	char s5[20] = "hello";
	char s6[] = "world!!";
	printf("%lu,", (unsigned long)ft_strlcat(s5, s6, size));
	printf("%s\n", s5);
	char s7[20] = "hello";
	char s8[] = "world!!";
	printf("%lu,", strlcat(s7, s8, size));
	printf("%s\n", s7);
	// size > dest + size
	size = 18;
	char s9[20] = "hello";
	char s10[] = "world!!";
	printf("%lu,", (unsigned long)ft_strlcat(s9, s10, size));
	printf("%s\n", s9);
	char s11[20] = "hello";
	char s12[] = "world!!";
	printf("%lu,", strlcat(s11, s12, size));
	printf("%s\n", s11);
}