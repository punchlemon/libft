/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:01:09 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/22 16:41:59 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		if (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		else
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
	}
	return (dest);
}
// #include <unistd.h>
// int main(){
// 	char dest[] = "hello";
// 	char src[] = "world";
// 	write(1, ft_strncpy(dest, src, 2), 5);
// }
