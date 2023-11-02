/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:54:50 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 12:10:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	add(int a, int b);
void	sub(int a, int b);
void	duv(int a, int b);
void	mul(int a, int b);
void	mod(int a, int b);
void	ft_putnbr(int nb);

void	init(char *op[], void (*f[])(int, int))
{
	op[0] = "+";
	f[0] = add;
	op[1] = "-";
	f[1] = sub;
	op[2] = "/";
	f[2] = duv;
	op[3] = "*";
	f[3] = mul;
	op[4] = "%";
	f[4] = mod;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while ('0' <= *str && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (sign * num);
}

int	main(int argc, char *argv[])
{
	char	*op[5];
	void	(*f[5])(int, int);
	int		i;

	init(op, f);
	if (argc == 4)
	{
		i = -1;
		while (++i < 5)
		{
			if (ft_strcmp(op[i], argv[2]) == 0)
			{
				f[i](ft_atoi(argv[1]), ft_atoi(argv[3]));
				break ;
			}
		}
		if (i == 5)
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
