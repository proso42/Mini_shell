/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:15:02 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 18:16:03 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_print_list_space(t_list *begin_list)
{
	t_list	*current;

	current = begin_list;
	if (begin_list)
	{
		while (current)
		{
			ft_putstr(current->data);
			write(1, " ", 1);
			current = current->next;
		}
	}
}
