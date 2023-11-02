/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:27:49 by retanaka          #+#    #+#             */
/*   Updated: 2023/10/11 06:41:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	srclen;

	i = 0;
	srclen = ft_strlen(src);
	while (i < srclen && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}


#include <string.h>
int main(){
	strlcpy("hello", "world", 0);
}
