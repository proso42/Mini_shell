/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:15:06 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:48:49 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

t_list	*get_arg_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*arg_cmd;

	arg_cmd = NULL;
	tmp = NULL;
	i = 0;
	while ((cmd[i] == ' ' || cmd[i] == '\t') && cmd[i])
		i++;
	j = i;
	while (cmd[i])
	{
		while (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i])
			i++;
		tmp = ft_strsub(cmd, j, i - j);
		j = i + 1;
		ft_push_back(&arg_cmd, ft_strdup(tmp));
		ft_strdel(&tmp);
		while ((cmd[i] == ' ' || cmd[i] == '\t') && cmd[i])
			i++;
		j = i;
	}
	return (arg_cmd);
}

int		check_cmd(char *cmd, t_info *info)
{
	t_list	*current;

	current = ft_list_find(info->cmd_list, cmd);
	if (current)
		return (1);
	return (0);
}

int		get_cmd(t_info *info, char *cmd)
{
	t_list	*arg_cmd;

	if (!(arg_cmd = get_arg_cmd(cmd)))
		return (0);
	if ((check_cmd(arg_cmd->data, info)))
		exec_cmd(arg_cmd, info->env_var_list);
	else
		ft_printf("{red}{bold}mini_shell: command not found:{res} %s\n",
				arg_cmd->data);
	ft_remove_list(&arg_cmd);
	return (1);
}
