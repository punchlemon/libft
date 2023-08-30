/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:11:47 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 23:30:05 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_exe_error(int error)
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
	char	**strs;
	t_input	kouzou;

	input = ft_read_input(fd, 1024);
	if (input == NULL)
		return (1);
	if (ft_check_newline_character(input) == 1)
		return (1);
	strs = ft_split(input, "\n");
	if (strs == NULL)
		return (1);
	if (ft_check_map(strs) == 1)
		return (1);
	if (ft_map_to_kouzou(strs, &kouzou) == 1)
		return (1);
	if (ft_solve(&kouzou) == 1)
		return (1);
	else
		ft_print_map(kouzou);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		error;
	int		fd;

	error = 1;
	if (argc == 1)
		error *= ft_exe_error(ft_all(0));
	else
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 2)
			{
				error *= ft_exe_error(ft_all(fd));
				close(fd);
			}
			else
				error *= ft_exe_error(1);
			write(1, "\n", 1);
		}
	}
	return (error);
}
