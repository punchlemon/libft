/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:10 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/12 19:00:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort(int *tab, int size)
{
	int	i;
	int	a;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			a = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = a;
		}
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		sort(tab, size);
		i++;
	}
}
