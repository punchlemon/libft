/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:47:13 by rnameki           #+#    #+#             */
/*   Updated: 2023/08/27 23:00:15 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	find_nbr(long nb, char *filename)
{
	int		i;
	char	*p;

	i = 0;
	p = check_row(i, filename);
	while (p != NULL)
	{
		if (nb == atoi_real(p))
		{
			free(p);
			return (i);
		}
		free(p);
		i++;
		p = check_row(i, filename);
	}
	return (-1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ':' && str[i] != '\0')
		i++;
	if (str[i] == ':')
	{
		i++;
		while (str[i] == ' ')
			i++;
		while (str[i] >= ' ' && str[i] <= '~')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	write_string(long nb, char *filename)
{
	int		n;
	char	*p;

	n = find_nbr(nb, filename);
	p = check_row(n, filename);
	ft_putstr(p);
	free(p);
}
