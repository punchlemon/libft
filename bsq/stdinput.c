/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:29:42 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 17:29:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_realloc(char **buff, int add_buff_size)
{
	int		buff_len;
	char	*new_buff;

	buff_len = 0;
	if (buff[buff_len])
		buff[buff_len++];
	new_buff = (char *)malloc(sizeof(char) * (buff_len + add_buff_size + 1));
	if (new_buff)
	{
		while (buff_len--)
			new_buff[buff_len] = buff[buff_len];
	}
}

char	*

char	*read_stdinput()
{
	char	*output;
	open
	ft_realloc(&output, add_buff_size);
	return (output);
}
