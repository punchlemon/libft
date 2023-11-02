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

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	if (str)
		return (0);
	count = 0;
	while (*str++)
		count++;
	return (count);
}


int	ft_check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_check_args(char *str, char *base)
{
	int		i;
	char	c;
	int		j;

	if (str || base)
		return (1);
	if (ft_strlen(str) < 1 || ft_strlen(base) < 3)
		return (1);
	i = -1;
	while (base[++i])
	{
		c = base[i];
		if (ft_check_space(c) == 0 || c == '+' || c == '-')
			return (1);
		j = i;
		while (base[++j])
			if (c == base[j])
				return (1);
	}
}

//int	ft_check_num_base(char)
//int	check_base(char *str)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (str[i])
//	{
//		if (str[i] == '-' || str[i] == '+')
//			return (0);
//		j = 0;
//		while (j < i)
//			if (str[i] == str[j++])
//				return (0);
//		i++;
//	}
//	if (i == 1)
//		return (0);
//	return (i);
//}

//int	check_num(char c, char *base, int len)
//{
//	int	i;

//	i = 0;
//	while (i < len)
//		if (c == base[i++])
//			return (i - 1);
//	return (len);
//}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	phase;
	int	i;

	if (check_args(str, base))
		return (0);
	result = 0;
	sign = 1;
	phase = 0;
	i = -1;
	while (str[++i])
	{
		if (phase == 0)
			phase += ft_check_space(str[i]);
		if (phase == 1)
		{
			if (str[i] == '-')
				sign = -sign;
			else if (str[i] != '+')
				phase++;
		}
		if (phase == 2)
			if (str[i] != '0')
				phase++;
		if (phase == 3)
		{
			if (ft_check_num_base(str[i], base) == -1)
				return (result);
			result *= ft_strlen(base);
			result += sign * ft_check_num_base(str[i], base);
		}
	}
}

#include <stdio.h>
int main(){
	printf("%d ", ft_atoi_base("hello", NULL));
	printf("%d ", ft_atoi_base("hello", ""));
	printf("%d ", ft_atoi_base("hello", "1"));
	printf("%d ", ft_atoi_base("hello", "1231"));
	printf("%d ", ft_atoi_base("hello", "123-"));
	printf("%d ", ft_atoi_base("hello", "123+"));
	printf("%d ", ft_atoi_base("hello", "123 "));
	printf("%d ", ft_atoi_base("hello", "123\t"));
	printf("%d ", ft_atoi_base("hello", "123\n"));
	printf("%d ", ft_atoi_base("hello", "123\v"));
	printf("%d ", ft_atoi_base("hello", "123\f"));
	printf("%d\n", ft_atoi_base("hello", "123\r"));
	printf("^check base^");
	char *str;
	str = NULL;
	printf("%d : ", atoi(str));
	printf("%d\n", ft_atoi_base(str, "0123456789"));
	str = "";
	printf("%d : ", atoi(str));
	printf("%d\n", ft_atoi_base(str, "0123456789"));
	str = "   \t\n42";
	printf("%d : ", atoi(str));
	printf("%d\n", ft_atoi_base(str, "0123456789"));
	str = "0123";
	printf("%d : ", atoi(str));
	printf("%d\n", ft_atoi_base(str, "0123456789"));
}
