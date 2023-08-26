/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 18:13:37 by retanaka         ###   ########.fr       */
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

int	count_words(char *str, char *sep)
{
	int	i;
	int	word_count;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (check_charset(str[i], sep))
			flag = 0;
		else
		{
			if (flag == 0)
			{
				flag = 1;
				word_count++;
			}
		}
		i++;
	}
	return (word_count);
}

int	store_str(char *str, char *sep)
{
	static int	d;
	int			i;
	int			char_count;
	int			flag;
	char		*result;

	flag = 0;
	char_count = 0;
	i = 0;
	while (str[i])
	{
		if (check_charset(str[i], sep))
			if (flag == 1)
				break ;
		else
		{
			flag = 1;
			char_count++;
		}
	}
	i = 0;
	result = (char *)malloc(sizeof(char) * char_count + 1);
	if (result != NULL)
	{
		while (str[i])
		{
			if (check_charset(str[i], sep))
				if (flag == 1)
					break ;
			else
			{
				if (flag == 0)
				{
					flag = 1;
					str[i] = i;
				}
			}
			i++;
		}
	}
}

int	check_charset(char c, char *charset)
{
	int	len;
	int	i;

	len = ftstrlen(charset);
	i = 0;
	while (i < len)
		if (c == charset[i])
			return (1);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		str_len;
	int		word_count;
	char	**result;
	int		i;

	str_len = ft_strlen(str);
	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * word_count + 1);
	result[word_count] = NULL;
	i = 0;
	while (i < word_count)
	{
		result[i] = store_str(str, charset);
		i++;
	}

}
