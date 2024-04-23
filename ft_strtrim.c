/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:23:39 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/21 14:34:07 by retanaka         ###   ########.fr       */
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

size_t	ft_check_first_set(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (!ft_is_str_set(s1[i], set))
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_calc_total(char const *s1, char const *set, size_t *start)
{
	size_t	i;
	int		mode;
	size_t	erase_count;
	size_t	buff;

	if (ft_strlen(s1) == 0)
		return (0);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strlen(s1));
	*start = ft_check_first_set(s1, set);
	erase_count = *start;
	buff = 0;
	mode = 1;
	i = *start;
	while (i < ft_strlen(s1))
	{
		if (mode == 0 && ft_is_str_set(s1[i], set))
			mode = 1;
		if (mode == 1 && !ft_is_str_set(s1[i], set))
		{
			mode = 0;
			buff = 0;
		}
		else if (mode == 1 && ft_is_str_set(s1[i], set))
			buff++;
		i++;
	}
	erase_count += buff;
	return (ft_strlen(s1) - erase_count);
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
	p[total] = '\0';
	i = 0;
	while (i < total)
	{
		p[i] = s1[i + start];
		i++;
	}
	return (p);
}
