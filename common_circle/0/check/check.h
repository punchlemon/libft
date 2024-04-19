/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:55:37 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/17 15:27:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H

# define CHECK_H
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <stddef.h>
# include <string.h>

void	ft_checkprint(const char *s, int r);
void	ft_check_isalpha(void);
void	ft_check_isdigit(void);
void	ft_check_isalnum(void);
void	ft_check_isascii(void);
void	ft_check_isprint(void);
void	ft_check_strlen(void);
void	ft_check_memset(void);
void	ft_check_bzero(void);
void	ft_check_memcpy(void);
void	ft_check_memmove(void);
void	ft_check_strlcpy(void);

#endif
