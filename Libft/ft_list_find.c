/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:24:03 by proso             #+#    #+#             */
/*   Updated: 2017/04/08 17:24:06 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list	*ft_list_find(t_list *begin_list, char *str)
{
	t_list *current;

	current = begin_list;
	if (current)
	{
		while (current)
		{
			if (!ft_strcmp(str, (char*)current->data))
				return (current);
			current = current->next;
		}
		return (NULL);
	}
	else
		return (NULL);
}
