/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:41:07 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 23:29:30 by retanaka         ###   ########.fr       */
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

//ft_read.c
char	*ft_read_input(int fd, int buff_size);

//ft_check_map.c
int		ft_check_newline_character(char *str);

//ft_split.c
char	**ft_split(char *str, char *charset);
char	*ft_strdup_sp(char *src, int start, int end);

//ft_check_map2.c
int		ft_check_map(char **str);

//ft_map_to_input.c
int		ft_map_to_kouzou(char **strs, t_input *kouzou);

//ft_solve.c
int		ft_solve(t_input *in);

//ft_print_map.c
void	ft_print_map(t_input kouzou);

//others
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str);
int		min(int a, int b, int c);

#endif