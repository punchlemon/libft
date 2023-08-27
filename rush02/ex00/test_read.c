/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:13:07 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/27 17:20:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	read_char(int open_f)
{
	char	buff[1];
	int		re;

	re = read(open_f, buff, 1);
	if (re == -1)
		return (0);
	return (buff[0]);
}

int	check_row_len(int open_f, int row)
{
	int		count;
	char	c;
	int		mode;
	int		row_len;

	mode = 0;
	count = 0;
	row_len = 0;
	while (count != row)
	{
		c = read_char(open_f);
		if (c == '\n')
			count++;
		if (mode == 0)
		{
			if (count == row - 1)
				mode = 1;
		}
		else
			row_len++;
	}
	return (row_len);
}

char	*make_malloc(int len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	return (result);
}

void	store_row(int open_f, int row, char **result)
{
	int		count;
	char	c;
	int		mode;
	int		i;

	mode = 0;
	count = 0;
	i = 0;
	while (count != row)
	{
		c = read_char(open_f);
		if (c == '\n')
			count++;
		if (mode == 0)
		{
			if (count == row - 1)
				mode = 1;
		}
		else
		{
			(*result)[i] = c;
			i++;
		}
	}
}

char	*check_row(int row)
{
	int		open_f;
	int		row_len;
	char	*result;

	open_f = open("numbers.dict", O_RDONLY);
	if (open_f == -1)
		return (NULL);
	else
	{
		row_len = check_row_len(open_f, row);
		result = make_malloc(row_len);
		close(open_f);
	}
	open_f = open("numbers.dict", O_RDONLY);
	if (open_f == -1)
		return (NULL);
	else
	{
		store_row(open_f, row, &result);
		close(open_f);
	}
	return (result);
}

#include <stdio.h>
int main()
{
	printf("%s", check_row(34));
}
