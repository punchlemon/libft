/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnameki <rnameki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:10:52 by rnameki           #+#    #+#             */
/*   Updated: 2023/08/27 23:25:32 by rnameki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_and_sprit(int argc, char **argv)
{
	long	number;
	char	*filename;

	if (argc == 2)
		filename = "numbers.dict";
	else
		filename = argv[1];
	dic_validation(filename);
	number = mock_atoi(argv[argc - 1]);
	if (number == -1)
		return (-1);
	if (check_number(number, filename) == -1)
		return (-1);
	split_number(number, filename);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check_and_sprit(argc, argv) == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}
