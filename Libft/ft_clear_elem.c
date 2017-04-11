/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:34:04 by proso             #+#    #+#             */
/*   Updated: 2017/04/08 12:49:38 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_clear_elem(t_list **begin_list, t_list *elem)
{
	t_list	*current;

	current = NULL;
	if (*begin_list)
	{
		if (*begin_list != elem)
		{
			current = *begin_list;
			while (current->next != elem)
				current = current->next;
			current->next = elem->next;
		}
			ft_strdel((char**)&elem->data);
			elem->size = 0;
			elem->next = NULL;
	}
}
