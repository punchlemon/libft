/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:08:16 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 11:19:57 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_num(char c, char *base, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (c == base[i++])
			return (i - 1);
	return (len);
}

int	ft_atoi_base(char *str, char *base)
{
	int			check;
	int			sign;
	long long	num;
	int			len;

	sign = 1;
	num = 0;
	len = check_base(base);
	if (len)
	{
		while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		while (*str == '-' || *str == '+')
			if (*str++ == '-')
				sign = -sign;
		while (check_num(*str, base, len) != len)
		{
			check = check_num(*str, base, len);
			num = num * len + check;
			str++;
		}
	}
	return (sign * num);
}

#include <stdio.h>
int main(){
	printf("%d\n", ft_atoi_base(" ", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base(" 80000000", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base(" -2", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base(" -2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("  +--+--+-b", "0123456789abcdef"));
	return 0;
}
