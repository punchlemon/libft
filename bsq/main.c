/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:11:47 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 21:31:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		error;

	error = 1;
	if (argc == 1)
	{
		fd = 0;
		error *= exe_error(ft_all(fd));
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 2)
			{
				error *= exe_error(ft_all(fd));
				close(fd);
			}
			else
				error *= exe_error(1);
			write(1, "\n", 1);
		}
	}
	return (error);
}

int	exe_error(int error)
{
	if (error != 0)
	{
		write(2, "map error", 9);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	ft_all(int fd)
{
	char	*input;
	t_input	kouzou;

	if (read_input(&input, 1024) == 1)
		return (1);
	if (check_strs(input, &kouzou) == 1)
		return (1);
	if (solve(&kouzou) == 1)
		return (1);
	else
		ft_print_map(kouzou);
	return (0);
}
