/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:05 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/22 13:24:13 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*buf;

	if (lst == NULL)
		return ;
	p = *lst;
	*lst = NULL;
	while (p != NULL)
	{
		buf = p -> next;
		ft_lstdelone(p, del);
		p = buf;
	}
}
