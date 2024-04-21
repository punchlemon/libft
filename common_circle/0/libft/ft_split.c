/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:23:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/21 12:30:14 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_count(char const *s1, char c)
{
	size_t	i;
	int		tf;
	size_t	count;

	if (s1[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	count = 0;
	tf = 1;
	i = 0;
	while (i < ft_strlen(s1))
	{
		if (tf != (s1[i] == c))
			count++;
		tf = (s1[i] == c);
		i++;
	}
	if (tf)
		return (count / 2);
	return ((count + 1) / 2);
}

char	*ft_set_str(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	total;
	size_t	i;
	char	*p;

	while (s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index] != '\0')
		(*index)++;
	total = *index - start;
	p = (char *)malloc((total + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < total && s[i + start] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	p[total] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	s_len;
	char	**p;
	size_t	i;
	size_t	index;

	s_len = 0;
	if (s != NULL)
		s_len = ft_strlen(s);
	count = ft_split_count(s, c);
	p = (char **)malloc((count + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	p[count] = NULL;
	i = 0;
	index = 0;
	while (i < count)
	{
		p[i] = ft_set_str(s, c, &index);
		i++;
	}
	return (p);
}
