/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isalpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:59:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:10:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_isalpha(void)
{
	int	r;
	int	i;

	r = 0;
	i = CHAR_MIN;
	while (i <= CHAR_MAX)
	{
		if (isalpha(i) != ft_isalpha(i))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}
