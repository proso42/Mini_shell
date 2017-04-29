/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:56:46 by proso             #+#    #+#             */
/*   Updated: 2017/04/26 11:56:48 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		search_exe(char *path, char *exe)
{
	DIR				*dirp;
	struct dirent	*buf;

	if (!(dirp = opendir(path)))
		return (0);
	buf = readdir(dirp);
	while (buf)
	{
		if (!(ft_strcmp(exe, buf->d_name)))
		{
			closedir(dirp);
			return (1);
		}
		buf = readdir(dirp);
	}
	closedir(dirp);
	return (0);
}

char	*get_next_path(int *i, int *j, char *env_path)
{
	*j = *i;
	while (env_path[*i] && env_path[*i] != ':')
		(*i)++;
	return (ft_strsub(env_path, *j, *i - *j));
}

int		check_relative_path(char *exe, t_list *env_var_list)
{
	char	*env_path;
	char	*path;
	int		i;
	int		j;

	if (!(env_path = get_env_var(env_var_list, "PATH")))
		return (0);
	i = 0;
	while (env_path[i])
	{
		path = get_next_path(&i, &j, env_path);
		if ((search_exe(path, exe)))
		{
			env_path = ft_strjoin(path, "/");
			env_path = ft_strjoinfree(env_path, exe, 3);
			exe = ft_strdup(env_path);
			ft_strdel(&env_path);
			ft_strdel(&path);
			return (1);
		}
		if (path)
			ft_strdel(&path);
		i++;
	}
	return (0);
}

int		check_absolute_path(char *path)
{
	char			*exe;
	int				i;
	int				ret;

	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	exe = ft_strsub(path, i + 1, ft_strlen(path));
	path[i] = '\0';
	ret = search_exe(path, exe);
	ft_strdel(&exe);
	path[i] = '/';
	return (ret);
}

int		check_valid_cmd(char *cmd, t_list *env_var_list)
{
	if (!cmd || cmd[0] == '\0')
		return (0);
	else if (cmd[0] == '/')
		return (check_absolute_path(cmd));
	else
		return (check_relative_path(cmd, env_var_list));
}
