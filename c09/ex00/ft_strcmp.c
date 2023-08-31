/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:20:50 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/24 09:43:51 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// #include <string.h>
// #include <stdio.h>
// int main(){
// 	char *s1 = "hello";
// 	char *s2 = "hella";
// 	printf("%d",strcmp(s1, s2));
// 	printf("%d",ft_strcmp(s1, s2));
// }
