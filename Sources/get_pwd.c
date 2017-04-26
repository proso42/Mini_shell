/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 23:34:59 by proso             #+#    #+#             */
/*   Updated: 2017/04/20 23:35:02 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

t_list	*get_pwd(t_list *env_var_list)
{
	t_list	*current;

	if (!env_var_list)
		return (NULL);
	current = env_var_list;
	while (ft_strcmp((((t_env*)(current->data))->env_name), "PWD") && current)
		current = current->next;
	return (current);
}

t_list	*get_oldpwd(t_list *env_var_list)
{
	t_list	*current;

	if (!env_var_list)
		return (NULL);
	current = env_var_list;
	while (ft_strcmp((((t_env*)(current->data))->env_name),
														"OLDPWD") && current)
		current = current->next;
	return (current);
}
