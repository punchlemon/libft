/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:22:48 by rnameki           #+#    #+#             */
/*   Updated: 2023/08/27 23:00:43 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	mock_atoi(char *str)
{
	int				i;
	unsigned int	num;
	int				count;

	i = 0;
	num = 0;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (num);
}

int	atoi_real(char *str)
{
	unsigned int	num;
	int				count;
	int				sign;

	num = 0;
	count = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

// #include "rush.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(void)
// {
//     // いくつかのテストケースを試してみます
//     char *str1 = "   -42";
//     char *str2 = "4193 with words";
//     char *str3 = "words and 987";
//     char *str4 = "-91283472332";
//     char *str5 = "42\t34";
//     char *str6 = "--42";

//     printf("\"%s\" -> %d\n", str1, ft_atoi(str1));  // Outputs: "-42" -> -42
//     printf("\"%s\" -> %d\n", str2, ft_atoi(str2)); 
	// Outputs: "4193 with words" -> 4193
//     printf("\"%s\" -> %d\n", str3, ft_atoi(str3)); 
	// Outputs: "words and 987" -> 0
//     printf("\"%s\" -> %d\n", str4, ft_atoi(str4)); 
	// Outputs: "-91283472332" -> 0 (or INT_MIN,
	// depending on the system and compiler)
//     printf("\"%s\" -> %d\n", str5, ft_atoi(str5));  // Outputs: "42\t34"
	// -> 42
//     printf("\"%s\" -> %d\n", str6, ft_atoi(str6));  // Outputs: "+-42" -> 0
// 	write(1, "\n", 1);
// 	printf("\"%s\" -> %d\n", str1, atoi(str1));  // Outputs: "-42" -> -42
//     printf("\"%s\" -> %d\n", str2, atoi(str2)); 
	// Outputs: "4193 with words" -> 4193
//     printf("\"%s\" -> %d\n", str3, atoi(str3));  // Outputs: "words and 987"
	// -> 0
//     printf("\"%s\" -> %d\n", str4, atoi(str4));  // Outputs: "-91283472332"
	// -> 0 (or INT_MIN, depending on the system and compiler)
//     printf("\"%s\" -> %d\n", str5, atoi(str5));  // Outputs: "42\t34" -> 42
//     printf("\"%s\" -> %d\n", str6, atoi(str6));

//     return (0);
// }
