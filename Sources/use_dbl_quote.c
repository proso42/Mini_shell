/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dbl_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:44:35 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 14:45:02 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char		*sub_var(char *str, t_list *env_var_list)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 1;
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '"')
		i++;
	name = ft_strsub(str, 1, i - 1);
	tmp = get_env_var(env_var_list, name);
	ft_strdel(&name);
	return (tmp);
}

/*char		*use_dbl_quote(char *arg, t_list *env_var_list)
{
	int		i;
	int		j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	str = ft_str_new(ft_strlen(arg));
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			tmp = sub_var(&(arg[i]), env_var_list);
			str = ft_strjoinfree(str, tmp, 3);
		}
	}
}*/
