/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:29 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 12:07:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base)
	{
		while (base[i])
		{
			if (base[i] == '-' || base[i] == '+')
				return (0);
			j = 0;
			while (j < i)
				if (base[i] == base[j++])
					return (0);
			i++;
		}
	}
	if (i < 2)
		return (0);
	return (i);
}

void	calculate(int *num, char *str, char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = -1;
		while (base[++j])
			if (base[j] == str[i])
				break ;
		if (j < base_len)
		{
			if (i == 0)
				*num *= j;
			else
				*num = (*num * base_len) + j * ((*num > 0) * 2 - 1);
		}
		else
		{
			if (i == 0)
				*num = 0;
			break ;
		}
		i++;
	}
}

void	check_digit(int num, int base_len, int *i)
{
	(*i)++;
	num /= base_len;
	if (num)
	{
		if (num < 0)
		{
			(*i)++;
			num = -num;
		}
		check_digit(num, base_len, i);
	}
}

void	zero_fill(char *array, int i)
{
	if (array)
		while (i--)
			*array++ = 0;
}
