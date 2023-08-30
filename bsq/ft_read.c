/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:22:18 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 21:41:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_concat_strs(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*result;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	len1 = strlen(str1);
	len2 = strlen(str2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = str1[i];
	i = -1;
	while (++i < len2)
		result[len1 + i] = str2[i];
	result[len1 + len2] = '\0';
	free(str1);
	free(str2);
	return (result);
}

char	*ft_read_input(int fd, int buff_size)
{
	int		ret;
	char	*input;
	char	*temp;

	temp = NULL;
	while (ret > 0)
	{
		temp = (char *)malloc(buff_size);
		if (temp == NULL)
			return (NULL);
		ret = read(fd, temp, buff_size);
		if (ret < 0)
			break ;
		input = ft_concat_strs(input, temp);
		if (input == NULL)
			return (NULL);
	}
	if (ret < 0)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
