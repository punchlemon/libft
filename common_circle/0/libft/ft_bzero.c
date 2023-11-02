/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:08:23 by retanaka          #+#    #+#             */
/*   Updated: 2023/10/11 07:04:15 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// int main(){
// 	char b[10];
// 	char ft_b[10];
// 	int len = 5;
// 	ft_bzero(ft_b, len);
// 	bzero(b, len);
// 	for(int i = 0; i < 10; i++){
// 		char c = ft_b[i] + '0';
// 		write(1, &c, 1);
// 	}
// 	write(1, "\n", 1);
// 	for(int i = 0; i < 10; i++){
// 		char c = b[i] + '0';
// 		write(1, &c, 1);
// 	}
// 	write(1, "\n", 1);
// }
