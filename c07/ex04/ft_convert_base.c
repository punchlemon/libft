/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:02:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 13:32:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *str);
int		convert_num(char c, char *base, int len);
int		check_result_len(int num, char *base, int len);
void	rc_print_nbr(long long nbr, char *base, int len);
void	print_nbr(long long nbr, char *base, int len);

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

	len = check_base(base);
	if (len)
	{
		result_len = check_result_len(num, base, len);
		result = (char *)malloc(sizeof(char) * result_len);
		store_result(num, base, len, result_len);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;

	num = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(num, base_to));
}

int main() {
	ft_convert_base("64", "0123456789", "01");
}
