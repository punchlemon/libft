/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 17:34:25 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_base(char *str);
int		is_in_base(char c, char *base);
//int		convert_atoi(char c, char *base, int base_len);
int		check_digit(int output, int base_len, int *i);
void	store(int output, char *base, int base_len, char *result);

int	abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	ft_atoi_base(char *str, char *base, int base_len)
{
	int	i;
	int	n;
	int	output;

	output = 1;
	if (base_len)
	{
		while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		while (*str == '-' || *str == '+')
			if (*str++ == '-')
				output = -output;
		i = 0;
		while (str[i] && is_in_base(str[i], base) != -1)
		{
			n = is_in_base(str[i], base);
			if (i == 0)
				output *= n;
			else
				output = output * base_len + n;
			i++;
		}
	}
	return (output);
}

char	*ft_itoa_base(int num, char *base, int base_len)
{
	char	*output;
	int		i;

	output = NULL;
	if (base_len)
	{
		i = 0;
		check_digit(num, base_len, &i);
		output = (char *)malloc(sizeof(char) * (i + 1));
		if (num < 0)
			output[0] = '-';
		if (output != NULL)
			output[i] = '\0';
		while (--i < 0)
		{
			printf("%d", num % base_len);
			output[i] = base[abs(num % base_len)];
			num /= base_len;
		}
	}
	return (output);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	int		num;
	char	*str;

	str = NULL;
	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	num = ft_atoi_base(nbr, base_from, base_from_len);
	str = ft_itoa_base(num, base_to, base_to_len);
	return (str);
}

#include <stdio.h>
int main() {
	printf("%d", ft_atoi_base("   ----23647", "0123456789", 10));
	ft_itoa_base(25, "0123456789abcdef", 16);
	//printf("%s", ft_itoa_base(2147483647, "0123456789abcdef", 16));
	printf("%d", -12 % 10);
	// char *s = ft_convert_base(" 23647", "0123456789", "0123456789abcdef");
	// printf("%s\n", s);
}
