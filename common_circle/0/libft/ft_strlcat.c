/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:25:44 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/22 10:36:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (dst == NULL || dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	copy_len = dstsize - dst_len;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	if (0 < (copy_len - 1))
	{
		i = 0;
		while (i < (copy_len - 1) && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = 0;
	}
	return (dst_len + src_len);
}
