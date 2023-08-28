/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:29 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 11:42:25 by retanaka         ###   ########.fr       */
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

int	convert_num(char c, char *base, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (c == base[i++])
			return (i - 1);
	return (len);
}

int	check_digit(int num, int len)
{
	static int	result_len;

	result_len++;
	if (num < 0)
		result_len++;
	if (num / len)
		return (check_digit(num / len, len));
	else
		return (result_len);
}

void	store(int num, char *base, int len, char *result)
{
	static int	digit;
	int			now;
	int			result_len;

	result_len = check_digit(num, len);
	if (digit == 0)
	{
		result[result_len] = '\0';
		if (num < 0)
		{
			result[0] = '-';
			num = -num;
			digit++;
		}
	}
	now = result_len - digit++ - 1;
	if (num / len)
		store(num / len, base, len, result);
	result[now] = base[num % len];
}
