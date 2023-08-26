/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:58:20 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 08:30:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*p;

	size = max - min;
	if (size <= 0)
		return ((int)(*range = NULL));
	*range = (int *)malloc(sizeof(int) * (size));
	p = *range;
	if (!p)
		return (-1);
	while (min < max)
		*p++ = min++;
	return (size);
}

// #include <stdio.h>
// int main(){
// 	int *p;
// 	int **pp = &p;
// 	if(ft_ultimate_range(pp, 0, 9)> 0)
// 		for (int i = 0; i < 9; i++)
// 			printf("%d", p[i]);
// 	free(p);
// }
