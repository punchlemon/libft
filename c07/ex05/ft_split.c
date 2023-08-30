/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/31 01:06:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*c;

	i = 0;
	while (src[i])
		i++;
	src_len = i + 1;
	c = (char *)malloc(src_len);
	if (!c)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		c[i] = src[i];
		i++;
	}
	return (c);
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

int	make_str(char *str, char *sep, char **output, int d)
{
	int		i;
	int		char_count;
	char	*temp;
	int		word_start;

	while (str[d] && check_charset(str[d], sep))
		d++;
	char_count = 0;
	word_start = d;
	while (str[d] && !check_charset(str[d], sep))
	{
		char_count++;
		d++;
	}
	temp = (char *)malloc(sizeof(char) * (char_count + 1));
	temp[char_count] = '\0';
	i = 0;
	while (i < char_count)
	{
		temp[i] = str[word_start + i];
		i++;
	}
	*output = temp;
	return (d);
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
	int		d;

	if (!str || !*str)
	{
		output = (char **)malloc(sizeof(char *) * 1);
		output[0] = NULL;
	}
	else if (!charset || !*charset)
	{
		output = (char **)malloc(sizeof(char *) * 2);
		output[0] = ft_strdup(str);
		output[1] = NULL;
	}
	else
	{
		make_strs(str, charset, &word_count, &output);
		i = -1;
		d = 0;
		while (++i < word_count)
			d = make_str(str, charset, &output[i], d);
	}
	return (output);
}

#include <stdio.h>
#include <unistd.h>
int main(){
	char **r = ft_split("hefjaieahafhaeijhfah", "h");
	int i = 0;
	while (r[i])
		printf("%s\n", r[i++]);
	printf("%s\n", r[i]);
}
