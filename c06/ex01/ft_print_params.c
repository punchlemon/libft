/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:51:58 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/17 18:55:31 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
}
