/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:44:32 by proso             #+#    #+#             */
/*   Updated: 2017/04/25 10:44:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		check_existence(int i, char *path)
{
	int		ok;

	ok = 0;
	if (path[i] == '/')
	{
		path[i] = '\0';
		ok = 1;
	}
	if ((access(path, F_OK)))
	{
		ft_putstr_color("mini_shell: cd: No such file or directory\n", C_RED);
		ft_strdel(&path);
		return (0);
	}
	if (ok)
		path[i] = '/';
	return (1);
}

int		check_permission(int i, char *path)
{
	int		ok;

	ok = 0;
	if (path[i] == '/')
	{
		path[i] = '\0';
		ok = 1;
	}
	if ((access(path, R_OK)))
	{
		ft_printf("{red}{bold}mini_shell: cd: Permission denied{res}\n");
		ft_strdel(&path);
		return (0);
	}
	if (ok)
		path[i] = '/';
	return (1);
}

int		check_directory(int i, char *path)
{
	struct stat	buf;
	int			ok;

	ok = 0;
	if (path[i] == '/')
	{
		path[i] = '\0';
		ok = 1;
	}
	stat(path, &buf);
	if ((buf.st_mode & S_IFMT) != S_IFDIR)
	{
		ft_printf("{red}{bold}mini_shell: cd: Not a directory{res}\n");
		ft_strdel(&path);
		return (0);
	}
	if (ok)
		path[i] = '/';
	return (1);
}

int		check_error(t_list *arg_cmd, t_list *env_var_list)
{
	int			i;
	char		*path;

	if (!arg_cmd->next || !arg_cmd->next->data ||
										!ft_strcmp(arg_cmd->next->data, "-"))
		return (0);
	if (!(path = replace_tild(ft_strdup(arg_cmd->next->data), env_var_list)))
		return (0);
	i = (path[0] == '/') ? 1 : 0;
	while (path[i])
	{
		while (path[i] && path[i] != '/')
			i++;
		if (!(check_existence(i, path)))
			return (1);
		if (!(check_permission(i, path)))
			return (1);
		if (!(check_directory(i, path)))
			return (1);
		if (path[i] == '/')
			i++;
	}
	ft_strdel(&path);
	return (0);
}
