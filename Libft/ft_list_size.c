/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:17:23 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:59:22 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*p;

	size = 0;
	p = begin_list;
	if (!begin_list)
		return (0);
	while (p)
	{
		p = p->next;
		size++;
	}
	return (size);
}
