/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:47:12 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:35:11 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_get_elem(t_list *begin_list, int i)
{
	t_list	*current;

	if (!begin_list || i < 0)
		return (NULL);
	current = begin_list;
	while (i > 0)
	{
		i--;
		if (current->next)
			current = current->next;
		else
			return (NULL);
	}
	return (current->data);
}
