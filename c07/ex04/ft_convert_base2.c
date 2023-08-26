/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:29 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 13:33:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = 0;
		while (j < i)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

int	convert_num(char c, char *base, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (c == base[i++])
			return (i - 1);
	return (len);
}

int	check_result_len(int num, char *base, int len)
{
	static int	result_len
}

void	store_result(int num, char *base, int len, int result_len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}

	if (nbr / len)
		rc_print_nbr(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}
