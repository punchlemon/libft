/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:11:47 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 17:11:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*strs;
	t_input	input;
	int		error;

	error = 0;
	if (argc == 1)
		read_stdinput(&strs);
	else
	{
		i = 1;
		while (i < argc)
			read_fileinput(argv[i++], &strs);
	}
	if (check_strs(strs))
	{
		change_struct(strs, &input);
		if (solve(&input))
			print_map(input);
		else
			error = 1;
	}
	else
		write(1, "map error\n", 10);

}
