/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:19:49 by proso             #+#    #+#             */
/*   Updated: 2017/04/11 17:19:52 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

char	*use_quote(char *arg, int *i)
{
	int		quote;
	int		j;
	char	*tmp;

	quote = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(arg));
	(*i)++;
	while (arg[*i] && arg[*i] != 39)
	{
		tmp[j] = arg[*i];
		(*i)++;
		j++;
		if (arg[*i] == 39)
			quote = 1;
	}
	if (!quote && (j || !arg[*i]))
		tmp = ft_strjoinfree(tmp, recursive_quote(), 3);
	if (arg[*i] == 39)
		(*i)++;
	return (tmp);
}
