/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:57:19 by proso             #+#    #+#             */
/*   Updated: 2017/04/26 10:57:22 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char	**get_tab_env(t_list *env_var_list)
{
	int		i;
	char	**envp;
	t_list	*current;

	current = env_var_list;
	i = 1;
	if (!env_var_list || !env_var_list->data)
		return (NULL);
	while (current)
	{
		current = current->next;
		i++;
	}
	if (!(envp = malloc(sizeof(char*) * i)))
		return (NULL);
	i = 0;
	current = env_var_list;
	while (current)
	{
		envp[i] = ((t_env*)(current->data))->env_complete;
		current = current->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

char	*find_cmd(char *cmd)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = ft_strlen(cmd);
	while (i >= 0 && (cmd)[i] != '/')
		i--;
	tmp = ft_strsub(cmd, i + 1, ft_strlen(cmd));
	return (tmp);
}

void	exec(t_list *arg_cmd, t_list *env_var_list)
{
	char			**args;
	char			**envp;
	char			*path;
	char			*cmd;
	extern pid_t	g_pid;

	args = NULL;
	envp = NULL;
	path = ft_strdup(arg_cmd->data);
	cmd = find_cmd(arg_cmd->data);
	g_pid = fork();
	if (g_pid == 0)
	{
		envp = get_tab_env(env_var_list);
		args = ft_list_to_tab(arg_cmd, cmd);
		execve(path, args, envp);
		ft_strdel(&path);
		ft_strdel(&cmd);
		free(args);
		free(envp);
		exit(EXIT_FAILURE);
	}
	wait(&g_pid);
	ft_strdel(&path);
	ft_strdel(&cmd);
}
