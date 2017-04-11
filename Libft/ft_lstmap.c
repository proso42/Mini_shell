/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:08 by proso             #+#    #+#             */
/*   Updated: 2016/11/26 16:24:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new_elem;

	new_elem = NULL;
	if (!lst)
		return (NULL);
	new_elem = f(lst);
	first = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem->next = f(lst);
		lst = lst->next;
		new_elem = new_elem->next;
	}
	new_elem->next = NULL;
	return (first);
}
