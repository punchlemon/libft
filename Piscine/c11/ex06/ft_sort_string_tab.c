/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:55:34 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 10:20:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_pointer(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[++j])
			if (ft_strcmp(tab[i], tab[j]) < 0)
				ft_swap_pointer(&tab[i], &tab[j]);
	}
}

// #include <stdio.h>
// int main(){
// 	char *ss[] = {"he", "fhea", "fhae", "fjiaj", NULL};
// 	int i = -1;
// 	while (ss[++i])
// 		printf("%s\n", ss[i]);
// 	printf("%s\n", ss[i]);

// 	ft_sort_string_tab(ss);
// 	printf("\n");

// 	i = -1;
// 	while (ss[++i])
// 		printf("%s\n", ss[i]);
// 	printf("%s\n", ss[i]);
// }
