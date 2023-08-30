/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:17:37 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 21:31:33 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_print_map(t_input kouzou)
{
	int	i;

	i = -1;
	while (++i < kouzou.col)
	{
		ft_putstr(kouzou.map[i]);
		write(1, "\n", 1);
	}
}
