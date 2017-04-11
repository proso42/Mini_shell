/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:43:33 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:55:19 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char		*add_str(char *arg, t_list *env_var_list)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(arg));
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			str = ft_strjoinfree(str, use_dol(&i, arg, env_var_list), 3);
			j = i;
		}
		else if (arg[i] == '"')
		{
			i++;
		}
		else if (arg[i] == 39)
		{
			str = ft_strjoinfree(str, use_quote(arg, &i), 3);
			j = i;
		}
		else
		{
			while (arg[i] && arg[i] != '$' && arg[i] != 39 && arg[i] != '"')
				i++;
			str = ft_strjoinfree(str, ft_strsub(arg, j, i - j), 3);
		}
	}
	return (str);
}

void    cmd_echo(t_list *env_var_list, t_list *arg_cmd)
{
	t_list	*current;
	t_list	*result;
	char		*tmp;

	current = NULL;
	if (arg_cmd->next)
		current = arg_cmd->next;
	result = NULL;
	tmp = NULL;
	while (current)
	{
		tmp = add_str(current->data, env_var_list);
		ft_push_back(&result, ft_strdup(tmp));
		ft_strdel(&tmp);
		current = current->next;
	}
	if (result)
	{
		ft_print_list_space(result);
		ft_remove_list(&result);
	}
	write(1, "\n", 1);
}
