/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:15 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/21 02:47:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[] = "abcdef";
//     char str2[] = "abcxyz";
//     printf("%s", ft_strcat(str1, str2));
//     printf("%s", strcat(str1, str2));
// }
