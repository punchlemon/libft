/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isalnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:23:49 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:10:51 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_isalnum(void)
{
	int	r;
	int	i;

	r = 0;
	i = CHAR_MIN;
	while (i <= CHAR_MAX)
	{
		if (isalnum(i) != ft_isalnum(i))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}
