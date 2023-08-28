/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:34:10 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/28 14:57:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*i;
	int			*ret;
	long long	size;

	size = (long long)max - (long long)min;
	if (max <= min)
		return (NULL);
	i = (int *)malloc(sizeof(int) * size);
	if (!i)
		return (NULL);
	ret = i;
	while (min < max)
		*i++ = min++;
	return (ret);
}

// #include <stdio.h>
// int main(){
// 	int min = -2147483648;
// 	int max = 2147483647;
// 	int *pi = ft_range(min, max);
// 	for (int i = 0; pi[i] <= max; i++)
// 		printf("%d", pi[i]);
// 	free(pi);
// }
