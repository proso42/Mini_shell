/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:32:20 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 17:32:25 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char	*use_dol(int *i, char *arg, t_list *env_var_list)
{
	int		stop;
	int		j;
	char	*tmp;
	char	*dol;

	stop = 0;
	(*i)++;
	j = *i;
	while (arg[*i] && !stop)
	{
		if (arg[*i] != '_' && !ft_isdigit(arg[*i]) && !ft_isalpha(arg[*i]))
			stop = 1;
		else
			(*i)++;
	}
	tmp = ft_strsub(arg, j, *i - 1);
	dol = get_env_var(env_var_list, tmp);
	ft_strdel(&tmp);
	return (ft_strdup(dol));
}
