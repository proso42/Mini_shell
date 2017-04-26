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

void	loop(char *arg, int *i, int *dbl_quote)
{
	while (arg[*i] && arg[*i] != '$' && arg[*i] != '"')
	{
		(*i)++;
		if (arg[*i] == '"')
			(*dbl_quote)++;
	}
}

void	init_var2(int *dbl_quote, int *j, int *i, char **tmp)
{
	*dbl_quote = 0;
	*j = *i;
	(*i)++;
	*tmp = NULL;
}

char	*use_dbl_quote(char *arg, int *i, t_list *env_var_list)
{
	int		dbl_quote;
	int		j;
	char	*tmp;

	init_var2(&dbl_quote, &j, i, &tmp);
	while (arg[*i] && arg[*i] != '"')
		if (arg[*i] == '$')
		{
			tmp = ft_strjoinfree(tmp, use_dollard(arg, i, env_var_list), 3);
			j = *i;
			dbl_quote += (arg[*i] == '"') ? 1 : 0;
		}
		else
		{
			loop(arg, i, &dbl_quote);
			if (*i - j != 0)
				tmp = ft_strjoinfree(tmp, ft_strsub(arg, j, (*i) - j), 3);
		}
	if (!(dbl_quote) && (j || !arg[*i]))
		tmp = ft_strjoinfree(tmp, recursive_dbl_quote(env_var_list), 3);
	if (arg[*i] == '"')
		(*i)++;
	tmp = ft_str_remove_c(tmp, '"');
	return (tmp);
}
