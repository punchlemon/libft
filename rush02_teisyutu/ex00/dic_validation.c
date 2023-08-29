/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:14:54 by adaichi           #+#    #+#             */
/*   Updated: 2023/08/27 21:29:42 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	row_validation(char *row)
{
	int	i;

	i = 0;
	while (row[i] == ' ')
		i++;
	while (row[i] != ' ')
		i++;
	while (row[i] == ' ')
		i++;
	if (row[i] != ':')
		return (-1);
	i++;
	while (row[i])
	{
		if (row[i] < 32 || row[i] > 126)
		{
			return (-1);
		}
		else
			i++;
	}
	return (0);
}

int	dic_validation(char *filename)
{
	int	i;

	i = 1;
	while (row_validation(check_row(i, filename)) == 0
		&& check_row(i, filename))
		i++;
	if (check_row(i, filename))
		return (-1);
	return (0);
}
