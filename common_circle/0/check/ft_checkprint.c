/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:40:31 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 09:12:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	ft_checkprint(const char *s, int r)
{
	if (r)
		printf("%s is NG\n", s);
	else
		printf("%s is OK\n", s);
}
