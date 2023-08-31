/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:50:43 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 12:08:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length < 3)
		return (1);
	i = -1;
	while (++i < length - 2)
		if (f(tab[i], tab[i + 1]) * f(tab[i + 1], tab[i + 2]) < 0)
			return (0);
	return (1);
}
