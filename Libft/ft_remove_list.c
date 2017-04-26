/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 22:15:15 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 20:20:14 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_remove_list(t_list **begin_list)
{
	t_list	*previous;

	while (*begin_list)
	{
		ft_strdel((char**)&(*begin_list)->data);
		previous = *begin_list;
		*begin_list = previous->next;
		free(previous);
	}
	*begin_list = NULL;
}
