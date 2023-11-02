/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:41:59 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 08:28:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	long long	num;
	char		c;

	num = nb;
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
			ft_putnbr((int)num);
		}
		else if (num == 0)
			write(1, "0", 1);
		else
		{
			c = num % 10 + '0';
			if (num / 10 != 0)
				ft_putnbr((int)(num / 10));
			write(1, &c, 1);
		}
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// int main(){
// 	char *str[] = {"hello", "aaaa"};
// 	char **p = str;
// 	t_stock_str *tss = ft_strs_to_tab(2, p);
// 	ft_show_tab(tss);
// }