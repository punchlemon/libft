/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:42:20 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 10:18:59 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

void	update_total_size(char **strs, char *sep, int size, int *total_size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*total_size += ft_strlen(strs[i++]);
		if (i != size)
			*total_size += ft_strlen(sep);
	}
}

char	*ft_strcat(char *dest, char *src)
{
	char	*result;

	result = dest;
	if (dest != NULL && src)
	{
		while (*dest)
			dest++;
		while (*src)
		{
			*dest = *src;
			dest++;
			src++;
		}		
		*dest = '\0';
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	int		i;
	char	*result;

	total_size = 1;
	if (!strs)
		update_total_size(strs, sep, size, &total_size);
	result = (char *)malloc(sizeof(char) * (total_size));
	if (result)
	{
		result[total_size - 1] = '\0';
		i = 0;
		while (i < size)
		{
			ft_strcat(result, strs[i++]);
			if (i != size)
				ft_strcat(result, sep);
		}
	}
	return (result);
}

// #include <stdio.h>
// int main() {
// 	// char *strs[] = {};
// 	char *strs[] = {};
// 	char *sep = NULL;
// 	free(ft_strjoin(0, strs, sep));
// 	printf("%s", ft_strjoin(0, strs, sep));
// }
