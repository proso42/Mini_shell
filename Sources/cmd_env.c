/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 11:54:16 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:44:29 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	cmd_env(t_list *env_var_list)
{
	t_list	*current;

	current = env_var_list;
	while (current)
	{
		ft_putendl(((t_env*)(current->data))->env_complete);
		current = current->next;
	}
}
