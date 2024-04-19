/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:55:17 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/19 11:55:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		count++;
	while ((n / 10) != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	s_len;
	char	*s;

	s_len = ft_itoa_count(n) + 1;
	s = (char *)malloc(s_len * sizeof(char));
	s[s_len] = '\0';
	while (s_len--)
	{
		s[s_len] = n % 10 + '0';
		if ((n % 10) < 0)
			s[s_len] = -(n % 10) + '0';
		if ((n / 10) == 0 && n < 0)
		{
			s[0] = '-';
			break ;
		}
		n /= 10;
	}
	return (s);
}
