/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:41:56 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:53:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_strlen(void)
{
	int		r;
	int		i;
	char	*a[4];

	a[0] = "hello";
	a[1] = "\0";
	a[2] = "";
	a[3] = NULL;
	r = 0;
	i = 0;
	while (i < 3)
	{
		if (strlen(a[i]) != ft_strlen(a[i]))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}

// I didn`t try NULL
