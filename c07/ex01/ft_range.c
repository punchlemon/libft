/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:34:10 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/25 07:19:01 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*i;
	int	*ret;

	if (max <= min)
		return (NULL);
	i = (int *)malloc(sizeof(int) * (max - min));
	if (!i)
		return (NULL);
	ret = i;
	while (min < max)
		*i++ = min++;
	return (ret);
}

// #include <stdio.h>
// int main(){
// 	int *pi = ft_range(0, 9);
// 	for (int i = 0; i < 9; i++)
// 		printf("%d", pi[i]);
// 	free(pi);
// }
