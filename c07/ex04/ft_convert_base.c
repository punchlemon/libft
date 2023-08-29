/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 09:25:20 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		abs(int num);
int		check_base(char *str);
void	calculate(int *num, char *str, char *base, int base_len);
int		check_digit(int output, int base_len, int *i);
void	zero_fill(char *array, int i);

int	ft_atoi_base(char *str, char *base, int base_len)
{
	int	i;
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
		calculate(&output, str, base, base_len);
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
		if (output != NULL)
		{
			zero_fill(output, i + 1);
			if (num < 0)
				output[0] = '-';
			output[i] = '\0';
			while (--i > -1 && output[i] != '-')
			{
				output[i] = base[abs(num % base_len)];
				num /= base_len;
			}
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
// #include <stdio.h>
// int main() {
// 	char *base_from = "0123456789";
// 	char *base_to = "0123456789abcdef";
// 	char *input = "  ---+2147483648";
// 	printf("%s\n", ft_convert_base(input, base_from, base_to));
// 	base_from = "0123456789";
// 	base_to = "0123456789abcdef";
// 	input = "  2147483647";
// 	printf("%s\n", ft_convert_base(input, base_from, base_to));
// }
