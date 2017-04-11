/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:16:15 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:46:44 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		add_env_var(t_list **env_var_list, char *name, char *value)
{
	t_list	*elem;
	t_env	*var_env;

	elem = NULL;
	if (!(var_env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	var_env->env_name = ft_strdup(name);
	var_env->env_value = ft_strdup(value);
	var_env->env_complete = ft_strjoin(name, "=");
	var_env->env_complete = ft_strjoinfree(var_env->env_complete, value, 1);
	ft_push_back(env_var_list, var_env);
	return (1);
}

void	edit_env_var(t_list *elem, char *name, char *value)
{
	char	*tmp;

	ft_strdel(&(((t_env*)(elem->data))->env_value));
	ft_strdel(&(((t_env*)(elem->data))->env_complete));
	((t_env*)(elem->data))->env_value = ft_strdup(value);
	tmp = ft_strjoin(name, "=");
	tmp = ft_strjoinfree(tmp, value, 1);
	((t_env*)(elem->data))->env_complete = ft_strdup(tmp);
	ft_strdel(&tmp);
}

t_list	*search_exist_value(t_list *env_var_list, char *name)
{
	t_list	*current;
	char	*tmp;

	current = env_var_list;
	tmp = ((t_env*)(current->data))->env_name;
	while (current && ft_strcmp(name, tmp))
	{
		current = current->next;
		if (current)
			tmp = ((t_env*)(current->data))->env_name;
	}
	if (!ft_strcmp(name, tmp))
		return (current);
	else
		return (NULL);
}

int		cmd_set_env(t_list **env_var_list, t_list *arg_cmd)
{
	t_list	*current;
	char	*name;
	char	*value;

	if (!arg_cmd->next || !arg_cmd->next->next)
		return (0);
	name = arg_cmd->next->data;
	value = arg_cmd->next->next->data;
	current = search_exist_value(*env_var_list, name);
	if (current)
		edit_env_var(current, name, value);
	else
		add_env_var(env_var_list, name, value);
	return (1);
}
