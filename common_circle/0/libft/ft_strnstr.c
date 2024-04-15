/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/15 17:03:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < needle_len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == needle_len - 1)
			return (i);
		i++;
	}
	return NULL;
}
