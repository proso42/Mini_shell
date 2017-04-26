/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:11:02 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:50:20 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

t_list	*init_cmd(void)
{
	t_list	*list;

	list = NULL;
	ft_push_back(&list, "env");
	ft_push_back(&list, "setenv");
	ft_push_back(&list, "unsetenv");
	ft_push_back(&list, "echo");
	ft_push_back(&list, "exit");
	ft_push_back(&list, "cd");
	return (list);
}

t_list	*init_env(void)
{
	extern char	**environ;
	int			i;
	t_list		*list;
	t_env		*var_env;

	i = 0;
	list = NULL;
	while (environ[i])
	{
		if (!(var_env = (t_env*)malloc(sizeof(t_env))))
			return (NULL);
		var_env->env_complete = ft_strdup(environ[i]);
		var_env->env_name = ft_strcdup(environ[i], '=');
		var_env->env_value = ft_strcsub(environ[i], '=');
		ft_push_back(&list, var_env);
		i++;
	}
	return (list);
}
