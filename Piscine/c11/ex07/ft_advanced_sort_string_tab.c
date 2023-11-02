/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:56:26 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 10:15:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_pointer(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[++j])
			if (cmp(tab[i], tab[j]) < 0)
				ft_swap_pointer(&tab[i], &tab[j]);
	}
}
