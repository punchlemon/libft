/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:29:32 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/21 08:21:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	s += ft_strlen(s) - 1;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
