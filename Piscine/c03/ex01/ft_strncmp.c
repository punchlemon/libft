/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:02 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/24 09:44:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 || *s2) && 0 < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[] = "abcdef";
//     char str2[] = "abcxyz";
//     unsigned int n = 3;

//     printf("%d", ft_strncmp(str1, str2, n));
//     printf("%d", strncmp(str1, str2, n));
// }
