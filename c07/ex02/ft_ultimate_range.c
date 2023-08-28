/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:58:20 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 15:32:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	int			*p;

	size = (long long)max - (long long)min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
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
// 	int min = 0;
// 	int max = 1;
// 	int *p;
// 	int **pp = &p;
// 	printf("%d", ft_ultimate_range(pp, min, max));
// 	// if(ft_ultimate_range(pp, min, max)> 0)
// 		// for (int i = 0; p[i] <= max; i++)
// 			// printf("%d", p[i]);
// 	free(p);
// }
