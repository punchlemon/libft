/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:03:59 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/21 14:39:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char *s = ft_itoa(n);
	write(1, "\n", 1);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	ft_putstr_fd(ft_itoa(n), fd);
}
