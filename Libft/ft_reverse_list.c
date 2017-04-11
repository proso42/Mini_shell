/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:12:52 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:27:52 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_reverse_list(t_list **begin_list)
{
	t_list	*current;
	t_list	*previous;
	t_list	*swap;

	current = *begin_list;
	previous = 0;
	while (current)
	{
		swap = current->next;
		current->next = previous;
		previous = current;
		current = swap;
	}
	*begin_list = previous;
}
