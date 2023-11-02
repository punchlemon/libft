/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:08:02 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 11:29:22 by retanaka         ###   ########.fr       */
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

void	rc_print_nbr(long long nbr, char *base, int len)
{
	if (nbr / len)
		rc_print_nbr(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	print_nbr(long long nbr, char *base, int len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	rc_print_nbr(nbr, base, len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = check_base(base);
	if (len)
		print_nbr((long long)nbr, base, len);
}

// int main(){
// 	ft_putnbr_base(-32, "0123456789abcdef");
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	return 0;
// }
