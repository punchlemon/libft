/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 18:04:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*str_dup(char *src)
{
	int		i;
	int		len;
	char	*copy_str;

	i = 0;
	while (src[i])
		i++;
	len = i + 1;
	copy_str = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		copy_str[i] = src[i];
		i++;
	}
	return (copy_str);
}

int	check_charset(char c, char *charset)
{
	int	i;

	if (charset)
	{
		i = 0;
		while (charset[i])
		{
			if (c == charset[i])
				return (1);
			i++;
		}
	}
	return (0);
}

void	make_str(char *str, char *sep, char **output)
{
	int		i;
	int		d;
	int		char_count;
	char	*temp;

	d = 0;
	while (check_charset(str[d], sep))
		d++;
	char_count = 0;
	while (!check_charset(str[d], sep) && str[d])
	{
		char_count++;
		d++;
	}
	temp = (char *)malloc(sizeof(char) * (char_count + 1));
	temp[char_count] = '\0';
	i = 0;
	while (i < char_count)
	{
		temp[i] = str[d];
		i++;
		d++;
	}
	*output = temp;
}

void	make_strs(char *str, char *sep, int *word_count, char ***output)
{
	int		i;
	int		flag;
	char	**temp;

	*word_count = 0;
	flag = 0;
	if (str)
	{
		i = -1;
		while (str[++i])
		{
			if (check_charset(str[i], sep))
				flag = 0;
			else if (flag == 0)
			{
				flag = 1;
				(*word_count)++;
			}
		}
	}
	temp = (char **)malloc(sizeof(char *) * (*word_count + 1));
	temp[*word_count] = NULL;
	*output = temp;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_count;
	char	**output;

	if (!str || !*str)
	{
		output = (char **)malloc(sizeof(char *) * 1);
		output[0] = NULL;
	}
	else if (!charset || !*charset)
	{
		output = (char **)malloc(sizeof(char *) * 2);
		output[0] = str_dup(str);
		output[1] = NULL;
	}
	else
	{
		make_strs(str, charset, &word_count, &output);
		i = -1;
		while (++i < word_count)
			make_str(str, charset, &output[i]);
	}
	return (output);
}

// #include <stdio.h>
// int main(){
// 	char **r = ft_split("he", NULL);
// 	int i = 0;
// 	while (r[i])
// 		printf("%s\n", r[i++]);
// 	printf("%s\n", r[i]);
// }
