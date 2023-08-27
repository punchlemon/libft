/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 06:30:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
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
		char_count = 0;
		while (check_charset(str[d], sep))
			d++;
		while (!check_charset(str[d], sep))
		{
			char_count++;
			d++;
		}
		result[i] = (char *)malloc(sizeof(char) * (char_count + 1));
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
		char_count = 0;
		while (check_charset(str[d], sep))
			d++;
		while (!check_charset(str[d], sep))
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
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	result[word_count] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = make_strs(str, charset);
	make_str(str, charset, result);
	store_str(str, charset, result);
	return (result);
}

// #include <stdio.h>
// int main(){
// 	char **r = ft_split("hef;jei.af;f.ejaio;ejfae;gal", ".;");
// 	for (int i = 0; r[i]; i++)
// 		printf("%s\n", r[i]);
// }
