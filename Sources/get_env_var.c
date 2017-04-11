/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:39:42 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:49:44 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char	*get_env_var(t_list *env_var_list, char *name)
{
	t_list	*current;
	char	*tmp;

	if (!env_var_list)
		return (NULL);
	current = env_var_list;
	tmp = ((t_env*)(current->data))->env_name;
	while (ft_strcmp(tmp, name) && current)
	{
		current = current->next;
		if (current)
			tmp = ((t_env*)(current->data))->env_name;
	}
	if (ft_strcmp(tmp, name))
		return (NULL);
	else
		return (((t_env*)(current->data))->env_value);
}
