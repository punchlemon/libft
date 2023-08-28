/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 11:54:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *str);
int		convert_num(char c, char *base, int len);
int		check_digit(int num, int len);
void	store(int num, char *base, int len, char *result);

int	ft_atoi_base(char *str, char *base)
{
	int			check;
	int			sign;
	long long	num;
	int			len;

	num = 1;
	len = check_base(base);
	if (len)
	{
		while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		while (*str == '-' || *str == '+')
			if (*str++ == '-')
				num = -num;
		while (convert_num(*str, base, len) != len)
		{
			check = convert_num(*str, base, len);
			num = num * len + check;
			str++;
		}
	}
	return (sign * num);
}

char	*ft_storenum_base(int num, char *base)
{
	int		len;
	int		result_len;
	char	*result;

	result = NULL;
	len = check_base(base);
	if (len)
	{
		result_len = check_digit(num, len);
		result = (char *)malloc(sizeof(char) * (result_len + 1));
		if (result != NULL)
			store(num, base, len, result);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;

	num = ft_atoi_base(nbr, base_from);
	return (ft_storenum_base(num, base_to));
}

#include <stdio.h>
int main() {
	printf("%d", ft_atoi_base(" 23647", "0123456789"));
	// char *s = ft_convert_base(" 23647", "0123456789", "0123456789abcdef");
	// printf("%s\n", s);
}
