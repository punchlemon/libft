/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:02:36 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/26 12:05:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	int		i;

	ft_sort(argc - 1, argv + 1);
	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
}
// void	ft_quick(int argc, char **argv)
// {
// 	char	**copy;
// 	int		index[2];
// 	int		i;

// 	copy = (char **)malloc(sizeof(char *) * argc);
// 	i = -1;
// 	while (++i < argc)
// 		copy[i] = argv[i];
// 	index[0] = 0;
// 	index[1] = 0;
// 	i = 0;
// 	while (++i < argc)
// 	{
// 		if (ft_strcmp(copy[0], copy[i]) > 0)
// 			argv[++index[0]] = copy[i];
// 		else
// 			argv[argc - ++index[1]] = copy[i];
// 	}
// 	if (1 < index[0])
// 		ft_quick(index[0], argv + index[0]);
// 	if (1 < index[1])
// 		ft_quick(index[1], argv + argc - index[1]);
// }
