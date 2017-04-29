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

void	pass_no_whitespace(char *cmd, int *i)
{
	while (!(ft_is_whitespace(cmd[*i])) && cmd[*i])
	{
		if (cmd[*i] == '\"')
		{
			(*i)++;
			while (cmd[*i] != '\"' && cmd[*i])
				(*i)++;
		}
		else if (cmd[*i] == '\'')
		{
			(*i)++;
			while (cmd[*i] != '\'' && cmd[*i])
				(*i)++;
		}
		if (cmd[*i])
			(*i)++;
	}
}

void	pass_whitespace(char *cmd, int *i, int *j)
{
	while ((ft_is_whitespace(cmd[*i])) && cmd[*i])
		(*i)++;
	*j = *i;
}

t_list	*get_arg_cmd(char *cmd)
{
	int		i;
	int		j;
	t_list	*arg_cmd;
	char	*tmp;

	arg_cmd = NULL;
	tmp = NULL;
	i = 0;
	pass_whitespace(cmd, &i, &j);
	while (cmd[i])
	{
		pass_no_whitespace(cmd, &i);
		if (i - j != 0)
			tmp = ft_strsub(cmd, j, i - j);
		j = i + 1;
		ft_push_back(&arg_cmd, ft_strdup(tmp));
		ft_strdel(&tmp);
		pass_whitespace(cmd, &i, &j);
	}
	return (arg_cmd);
}

int		check_builtin(char *cmd, t_info *info)
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
	if ((check_builtin(arg_cmd->data, info)))
		builtin(arg_cmd, &(info->env_var_list));
	else if (check_valid_cmd(arg_cmd->data, info->env_var_list))
		exec(arg_cmd, info->env_var_list);
	else
		ft_printf("{red}{bold}mini_shell: command not found:{res} %s\n",
				arg_cmd->data);
	ft_remove_list(&arg_cmd);
	return (1);
}
