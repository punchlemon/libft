/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:17:32 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:11:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_check_isdigit(void)
{
	int	r;
	int	i;

	r = 0;
	i = CHAR_MIN;
	while (i <= CHAR_MAX)
	{
		if (isdigit(i) != ft_isdigit(i))
			r = 1;
		i++;
	}
	ft_checkprint(__func__, r);
}
