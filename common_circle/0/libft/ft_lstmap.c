/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:09:10 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/22 14:46:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	lst_len;
	t_list	*map;
	t_list	*new;
	t_list	*next_lst;

	map = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst_len = ft_lstsize(lst);
	if (lst_len == 0)
		return (NULL);
	while (lst != NULL)
	{
		next_lst = lst -> next;
		new = ft_lstnew((*f)(lst -> content));
		if (new == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new);
		lst = next_lst;
	}
	return (map);
}
