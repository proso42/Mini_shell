/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dolllard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:32:20 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 17:32:25 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		is_bad_char(char c)
{
	return (c != '_' && !ft_isdigit(c) && !ft_isalpha(c));
}

int		check_wrong_dol(int *i, char *arg)
{
	if (is_bad_char(arg[*i + 1]) && arg[*i + 1] != '$')
		return (1);
	else if (arg[*i + 1] == '$')
		return (2);
	return (0);
}

char	*use_dollard(char *arg, int *i, t_list *env_var_list)
{
	int		j;
	char	*tmp;
	char	*dol;

	tmp = NULL;
	ft_printf("1\n");
	j = check_wrong_dol(i, arg);
	ft_printf("1\n");
	if (j == 2)
	{
		(*i) += 2;
		return (ft_itoa(getpid()));
	}
	else if (j == 1)
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	ft_printf("1\n");
	(*i)++;
	ft_printf("1\n");
	j = *i;
	ft_printf("1\n");
	while (arg[*i] && !(is_bad_char(arg[*i])))
		(*i)++;
	ft_printf("1\n");
	if (*i - j != 0)
		tmp = ft_strsub(arg, j, *i - j);
	dol = get_env_var(env_var_list, tmp);
	ft_strdel(&tmp);
	return ((dol) ? ft_strdup(dol) : NULL);
}
