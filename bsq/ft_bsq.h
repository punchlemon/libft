/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:41:07 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 21:22:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h> //read, write
# include <fcntl.h> //open, close
# include <stdlib.h> //malloc, free, exit

// 必要だったら
// # define BUFFERSIZE 1024とか

struct s_input
{
	char	**map;
	int		row;
	int		col;
	char	emp;
	char	obs;
	char	ful;
};

struct s_pos
{
	int	x;
	int	y;
	int	num;
};

typedef struct s_input	t_input;
typedef struct s_pos	t_pos;

void	gen_int_map(t_input *in, int ***int_map);
void	init_int_map(t_input *in, int **int_map);
int		min(int a, int b, int c);
void	calc_int_map(t_input *in, int **int_map);
void	find_max_pos(t_input *in, int **int_map, t_pos *max);
void	fill_in_map(t_input *in, t_pos *max);

//others
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str);

#endif