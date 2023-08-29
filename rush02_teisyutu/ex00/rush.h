/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaichi <adaichi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:47:18 by rnameki           #+#    #+#             */
/*   Updated: 2023/08/27 21:15:02 by adaichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		mock_atoi(char *str);
int		is_space(char *str);
void	split_number(long nb, char *filename);
int		judge_scale(int nb);
void	put_two_dig(long nb, char *filename);
void	recursive_split(long nb, int scale, int depth, char *filename);
char	*check_row(int row, char *filename);
void	store_row(int open_f, int row, char **result);
char	*make_malloc(int len);
int		check_row_len(int open_f, int row);
char	read_char(int open_f);
void	ft_putstr(char *str);
int		row_validation(char *row);
int		dic_validation(char *filename);
int		find_nbr(long nb, char *filename);
void	ft_putstr(char *str);
void	write_string(long nb, char *filename);
int		atoi_real(char *str);
int		check_number(long nb, char *filename);
int		recursive_check(long nb, int scale, int depth, char *filename);

#endif