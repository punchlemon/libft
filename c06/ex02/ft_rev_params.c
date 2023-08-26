/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:56:00 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/17 19:02:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	while (0 < --argc)
	{
		while (*argv[argc])
			write(1, argv[argc]++, 1);
		write(1, "\n", 1);
	}
}
