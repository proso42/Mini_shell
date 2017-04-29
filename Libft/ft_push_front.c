/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:03:42 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:47:35 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list	*ft_push_front(t_list **begin_list, char *str)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	elem->data = str;
	elem->size = (int)ft_strlen(str);
	if (!*begin_list)
		elem->next = NULL;
	else
		elem->next = *begin_list;
	*begin_list = elem;
	return (elem);
}
