/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:38:30 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/13 22:49:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	a;

	i = 0;
	while (i < (size / 2))
	{
		a = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = a;
		i++;
	}
}
