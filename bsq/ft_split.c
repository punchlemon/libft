/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:28:16 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/29 13:28:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check_charset(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && ft_check_charset(str[i], charset) == 0)
			i++;
	}
	return (count);
}

int	ft_word_range(char *str, char *charset, int *i)
{
	int	start;

	while (str[*i] != '\0' && ft_check_charset(str[*i], charset) == 1)
		(*i)++;
	start = *i;
	while (str[*i] != '\0' && ft_check_charset(str[*i], charset) == 0)
		(*i)++;
	return (start);
}

char	*ft_strdup_sp(char *src, int start, int end)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		temp[i] = src[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char *str, char *charset)
{
	char	**temp;
	int		i;
	int		start;
	int		j;

	temp = (char **)malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (temp == NULL)
		return (NULL);
	temp[ft_word_count(str, charset)] = 0;
	if (ft_word_count(str, charset) == 0)
		return (temp);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		start = ft_word_range(str, charset, &i);
		temp[j] = ft_strdup_sp(str, start, i);
		if (temp[j] == NULL)
			return (NULL);
		j++;
	}
	return (temp);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test_str = "asdf12345asdf678hj78  789   ";
// 	char	*test_charset = "asd";
// 	char	**p;
// 	int		i;

// 	p = ft_split(test_str, test_charset);
// 	if (p == NULL)
// 		return (-1);
// 	i = 0;
// 	while (p[i] != 0)
// 	{
// 		printf("%d : %s\n", i, p[i]);
// 		i++;
// 	}
// 	printf("%d : %s\n", i, p[i]);
// 	return (0);
// }