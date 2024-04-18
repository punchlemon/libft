/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:23:02 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/19 06:35:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total;
	char	*p;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (s2 == NULL)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);	
	total = s1_len + s2_len + 1;
	p = (char *)malloc(total * sizeof(char));
	if (p == NULL)
		return (NULL);
	p[total - 1] = '\0';
	while (s2_len--)
		p[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		p[s1_len] = s1[s1_len];
	return (p);
}
