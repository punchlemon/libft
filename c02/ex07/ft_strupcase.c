/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:10:56 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/14 17:54:40 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if ('a' <= *s && *s <= 'z')
			*s = *s - 'a' + 'A';
		s++;
	}
	return (str);
}
