/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:08:41 by proso             #+#    #+#             */
/*   Updated: 2017/04/30 00:03:11 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		builtin(t_list *arg_cmd, t_list **env_var_list)
{
	if (!ft_strcmp(arg_cmd->data, "env"))
		cmd_env(*env_var_list);
	else if (!ft_strcmp(arg_cmd->data, "exit"))
		exit(0);
	else if (!ft_strcmp(arg_cmd->data, "setenv"))
		cmd_set_env(env_var_list, arg_cmd);
	else if (!ft_strcmp(arg_cmd->data, "unsetenv"))
	{
		if ((cmd_unset_env(env_var_list, arg_cmd)) == -1)
			ft_putstr_color("mini_shell: unsetenv: Unknow variable\n", C_RED);
	}
	else if (!ft_strcmp(arg_cmd->data, "echo"))
		cmd_echo(*env_var_list, arg_cmd);
	else if (!ft_strcmp(arg_cmd->data, "cd"))
	{
		if ((cmd_cd(env_var_list, arg_cmd)) == 2)
			ft_putstr_color("mini_shell: cd: Missing home env variable\n"
																	, C_RED);
	}
	return (0);
}
