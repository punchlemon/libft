/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:22:24 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/21 02:08:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[(c >> 4) & 0x0f], 1);
	write(1, &hex[c & 0x0f], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write(1, "\\", 1);
			print_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

// int	main(void)
// {
// 	char str[4];
// 	str[0] = 0xa3;
// 	str[1] = 0x16;
// 	str[2] = 'a';
// 	str[3] = 0x58;
// 	ft_putstr_non_printable(str);
// 	return (0);
// }
