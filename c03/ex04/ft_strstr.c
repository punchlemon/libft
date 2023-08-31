/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:40 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 13:02:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (!*s2)
			return (0);
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (ft_strcmp(str, to_find) == 0)
			return (str);
		else
			str++;
	}
	return ((void *)0);
}

#include <stdio.h>
#include <string.h>
int main(){
	printf("%s", strstr("hello", "ll"));
}
