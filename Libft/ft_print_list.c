/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 19:14:16 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 19:52:38 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_print_list(t_list *begin_list)
{
	t_list	*current;

	current = begin_list;
	if (begin_list)
	{
		while (current)
		{
			ft_putendl(current->data);
			current = current->next;
		}
	}
}
