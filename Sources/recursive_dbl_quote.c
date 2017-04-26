/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_dbl_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 23:13:24 by proso             #+#    #+#             */
/*   Updated: 2017/04/11 23:13:26 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	loop_1(int *j, char *tmp, char *dol)
{
	int		k;

	k = 0;
	while (dol[k])
	{
		tmp[*j] = dol[k];
		(*j)++;
		k++;
	}
	ft_strdel(&dol);
}

char	*transform(char *str, t_list *env_var_list)
{
	char	*tmp;
	char	*dol;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(1024);
	while (str[i])
	{
		while (str[i] && str[i] != '$')
		{
			tmp[j] = str[i];
			j++;
			i++;
		}
		if (str[i] == '$')
		{
			dol = use_dollard(str, &i, env_var_list);
			if (dol)
				loop_1(&j, tmp, dol);
		}
	}
	ft_strdel(&str);
	return (tmp);
}

char	*recursive_dbl_quote(t_list *env_var_list)
{
	char	*tmp;
	char	*rep;
	int		dbl_quote;
	int		i;

	tmp = NULL;
	dbl_quote = 1;
	while ((dbl_quote % 2))
	{
		ft_putstr("dquote> ");
		rep = ft_strnew(1024);
		read(0, rep, 1024);
		rep = ft_str_remove_c(rep, '\n');
		rep = transform(rep, env_var_list);
		i = 0;
		while (rep[i])
		{
			dbl_quote += (rep[i] == '"') ? 1 : 0;
			i++;
		}
		rep = (dbl_quote > 1) ? ft_str_remove_c(rep, '"') : rep;
		tmp = ft_strjoinfree(tmp, "\n", 1);
		tmp = ft_strjoinfree(tmp, rep, 3);
	}
	return (tmp);
}
