/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:35:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 11:12:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*buf;
	int	i;

	buf = (int *)malloc(sizeof(int) * length);
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		buf[i] = f(tab[i]);
	return (buf);
}
