/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:29 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 17:34:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base)
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

int	is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
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


//void	store(int num, char *base, int base_len, char *result)
//{
//	static int	digit;
//	int			now;
//	int			result_len;

//	result_len = check_digit(num, base_len);
//	if (digit == 0)
//	{
//		result[result_len] = '\0';
//		if (num < 0)
//		{
//			result[0] = '-';
//			num = -num;
//			digit++;
//		}
//	}
//	now = result_len - digit++ - 1;
//	if (num / base_len)
//		store(num / base_len, base, base_len, result);
//	result[now] = base[num % base_len];
//}
