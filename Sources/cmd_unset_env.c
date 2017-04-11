/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:32:24 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:47:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	del_elem(t_list **begin_list, t_list *elem)
{
	t_list	*current;

	current = NULL;
	if (*begin_list)
	{
		if (*begin_list != elem)
		{
			current = *begin_list;
			while (current->next != elem)
				current = current->next;
			current->next = elem->next;
		}
		ft_strdel(&(((t_env*)(elem->data))->env_complete));
		ft_strdel(&(((t_env*)(elem->data))->env_name));
		ft_strdel(&(((t_env*)(elem->data))->env_value));
		free(elem->data);
	}
}

int		cmd_unset_env(t_list **env_var_list, t_list *arg_cmd)
{
	t_list	*current;
	char	*tmp;
	char	*name;

	if (!arg_cmd->next)
		return (0);
	name = arg_cmd->next->data;
	current = *env_var_list;
	tmp = ((t_env*)(current->data))->env_name;
	while (current && ft_strcmp(tmp, name))
	{
		current = current->next;
		if (current)
			tmp = ((t_env*)(current->data))->env_name;
	}
	if (!ft_strcmp(tmp, name))
	{
		del_elem(env_var_list, current);
		return (1);
	}
	return (0);
}
