/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:07:11 by proso             #+#    #+#             */
/*   Updated: 2017/04/13 16:07:13 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char	*replace_tild(char *path, t_list *env_var_list)
{
	char	*new_path;
	char	*home;

	if (!(home = get_env_var(env_var_list, "HOME")))
	{
		ft_putstr_color("mini_shell: cd: missing home env variable\n", C_RED);
		ft_strdel(&path);
		return (NULL);
	}
	if (path[0] == '~')
	{
		new_path = ft_strjoinfree(home,
									ft_strsub(path, 1, ft_strlen(path) - 1), 2);
		ft_strdel(&path);
		return (new_path);
	}
	return (path);
}

void	change_current_dir(t_list **env_var_list, char *path)
{
	char	buf[126];

	if (!(get_env_var(*env_var_list, "OLDPWD")))
		add_env_var(env_var_list, "OLDPWD", getcwd(buf, 126));
	else
		edit_env_var(get_oldpwd(*env_var_list), "OLDPWD", getcwd(buf, 126));
	chdir(path);
	if (!(get_env_var(*env_var_list, "PWD")))
		add_env_var(env_var_list, "PWD", getcwd(buf, 126));
	else
		edit_env_var(get_pwd(*env_var_list), "PWD", getcwd(buf, 126));
}

int		cmd_cd(t_list **env_var_list, t_list *arg_cmd)
{
	char	*path;
	char	*tmp;

	tmp = NULL;
	path = NULL;
	if ((check_error(arg_cmd, *env_var_list)) >= 1)
		return (0);
	if (!arg_cmd->next || !arg_cmd->next->data)
		tmp = get_env_var(*env_var_list, "HOME");
	else if (!(ft_strcmp(arg_cmd->next->data, "-")))
		tmp = get_env_var(*env_var_list, "OLDPWD");
	else
		tmp = (arg_cmd->next->data);
	if (tmp)
		path = ft_strdup(tmp);
	else
		return (0);
	if (!(path = replace_tild(path, *env_var_list)))
		return (0);
	change_current_dir(env_var_list, path);
	ft_strdel(&path);
	return (1);
}
