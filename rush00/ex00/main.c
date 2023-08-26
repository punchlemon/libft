/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:14:56 by yusatou           #+#    #+#             */
/*   Updated: 2023/08/13 22:28:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define INT_MAX 2147483647

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	my_pow(int n)
{
	int	result;

	if (n >= 10 || n < 0)
		return (-1);
	result = 1;
	while (n > 0)
	{
		result *= 10;
		n--;
	}
	return (result);
}

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_valid_str(char *str)
{
	int	loop;
	int	str_len;

	loop = 0;
	str_len = my_strlen(str);
	while (loop < str_len)
	{
		if (loop == 0 && !(str[loop] >= '1' && str[loop] <= '9'))
			return (0);
		else if (loop > 0 && !(str[loop] >= '0' && str[loop] <= '9'))
			return (0);
		loop++;
	}
	return (1);
}

int	to_int(char *str)
{
	long	result;
	int		str_len;
	int		digits;

	result = 0;
	str_len = my_strlen(str);
	while (*str != '\0')
	{
		digits = my_pow(--str_len);
		if (digits == -1)
			return (-1);
		result += (*str - '0') * digits;
		if (result > INT_MAX)
			return (-1);
		str++;
	}
	return ((int)result);
}

int	main(int argc, char *argv[])
{
	int	width;
	int	height;

	if (argc == 1)
		rush03(5, 3);
	else if (argc == 2)
		write(2, "Invalid arguments", 18);
	else if (argc >= 3)
	{
		if (is_valid_str(argv[1]) && is_valid_str(argv[2]))
		{
			width = to_int(argv[1]);
			height = to_int(argv[2]);
			if (width == -1 || height == -1)
				write(2, "Argument number too large", 26);
			else
				rush03(width, height);
		}
		else
			write(2, "Invalid arguments", 18);
	}
	return (0);
}
