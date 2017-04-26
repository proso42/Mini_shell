/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:12:34 by proso             #+#    #+#             */
/*   Updated: 2017/04/26 11:12:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	**ft_list_to_tab(t_list *begin_list)
{
	int		i;
	char	**args;
	t_list	*current;

	if (!begin_list)
		return (NULL);
	i = ft_list_size(begin_list);
	current = begin_list;
	if (!(args = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (current)
	{
		args[i] = current->data;
		current = current->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}
