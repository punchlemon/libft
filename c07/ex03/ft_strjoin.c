/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:42:20 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 11:03:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	int		i;
	char	*result;

	total_size = -ft_strlen(sep);
	i = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]) + ft_strlen(sep);
	result = (char *)malloc(sizeof(char) * (total_size + 1));
	result[total_size] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i++]);
		if (i != size)
			ft_strcat(result, sep);
	}
	return (result);
}

//#include <stdio.h>
//int main() {
//	char *strs[3] = {"hello", "world", "!!"};
//	char *sep = "\\";
//	printf("%s", ft_strjoin(3, strs, sep));
//}
