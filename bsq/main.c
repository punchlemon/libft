/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:11:47 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 23:04:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		error;

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

	if (ft_read_input(&input, 1024) == 1)
		return (1);
	if (ft_check_newline_character(char *str) == 1)
		return (1);
	if (ft_split(str, "\n") == NULL)
		return (1);
	else
		strs = ft_split(str, "\n");
	if (ft_check_map(input) == 1)
		return (1);
	if (ft_map_to_kouzou(strs, &kouzou) == 1)
		return (1);
	if (ft_solve(&kouzou) == 1)
		return (1);
	else
		ft_print_map(kouzou);
	return (0);
}
