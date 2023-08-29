/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/29 11:02:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	make_str(char *str, char *sep, char **result)
{
	int		i;
	int		d;
	int		char_count;

	d = 0;
	i = 0;
	while (result[i])
	{
		while (check_charset(str[d], sep))
			d++;
		char_count = 0;
		while (!check_charset(str[d], sep) && str[d])
		{
			char_count++;
			d++;
		}
		result[i] = (char *)malloc(sizeof(char) * (char_count + 1));
		if (result[i] != NULL)
			result[i][char_count] = '\0';
		i++;
	}
}

void	store_str(char *str, char *sep, char **result)
{
	int		i;
	int		d;
	int		char_count;

	d = 0;
	i = 0;
	while (result[i])
	{
		while (check_charset(str[d], sep))
			d++;
		char_count = 0;
		while (!check_charset(str[d], sep) && str[d])
		{
			result[i][char_count] = str[d];
			char_count++;
			d++;
		}
		result[i][char_count] = '\0';
		i++;
	}
}

char	**make_strs(char *str, char *sep)
{
	int		i;
	int		word_count;
	int		flag;
	char	**result;

	word_count = 0;
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
				word_count++;
			}
		}
	}
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result != NULL)
		result[word_count] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = NULL;
	result = make_strs(str, charset);
	if (result != NULL)
	{
		make_str(str, charset, result);
		store_str(str, charset, result);
	}
	return (result);
}

// #include <stdio.h>
// int main(){
// 	char **r = ft_split(NULL, "l");
// 	int i = 0;
// 	while (r[i])
// 		printf("%s\n", r[i++]);
// 	printf("%s\n", r[i]);
// 	i = 0;
// 	while (r[i])
// 		free(r[i++]);
// 	free(r);
// }
