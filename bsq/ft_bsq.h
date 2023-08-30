/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:41:07 by akyoshid          #+#    #+#             */
/*   Updated: 2023/08/30 15:41:08 by akyoshid         ###   ########.fr       */
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
	int		row;//横の長さ
	int		col;//縦の長さ
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

//使用する関数のプロトタイプ宣言を追加していく
//
//
//
//
//

#endif