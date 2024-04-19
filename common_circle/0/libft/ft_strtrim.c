/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:23:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/19 11:57:35 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str_set(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_calc_total(char const *s1, char const *set, size_t *start)
{
	size_t	i;
	size_t	end;

	if (ft_strlen(s1) == 0)
		return (0);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strlen(s1));
	i = 0;
	while (ft_is_str_set(s1[i], set))
		i++;
	*start = i;
	i = ft_strlen(s1) - 1;
	while (ft_is_str_set(s1[i], set))
		i--;
	end = i;
	return (end - *start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	total;
	char	*p;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	total = ft_calc_total(s1, set, &start);
	p = (char *)malloc((total + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		p[i] = s1[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
