/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:15:24 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:16:58 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_isascii(void)
{
	int	r;
	int	i;

	r = 0;
	i = CHAR_MIN;
	while (i <= CHAR_MAX)
	{
		if (isascii(i) != ft_isascii(i))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}
