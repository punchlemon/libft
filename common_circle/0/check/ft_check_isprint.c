/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:18:22 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:19:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_isprint(void)
{
	int	r;
	int	i;

	r = 0;
	i = CHAR_MIN;
	while (i <= CHAR_MAX)
	{
		if (isprint(i) != ft_isprint(i))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}
