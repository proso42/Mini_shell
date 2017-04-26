/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:05:59 by proso             #+#    #+#             */
/*   Updated: 2017/04/08 12:12:57 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_push_back(t_list **begin_list, void *str)
{
	t_list	*current;
	t_list	*new;

	current = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!*begin_list)
		*begin_list = new;
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	new->data = str;
	new->size = 0;
	new->next = NULL;
	return (1);
}
