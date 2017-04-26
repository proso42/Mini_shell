/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recursive_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:45:17 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:51:32 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	init_var(char **tmp, char **rep, int *quote)
{
	*rep = NULL;
	*tmp = NULL;
	*quote = 1;
}

char	*recursive_quote(void)
{
	char	*tmp;
	char	*rep;
	int		quote;
	int		i;

	init_var(&tmp, &rep, &quote);
	while ((quote % 2))
	{
		ft_putstr("quote> ");
		get_next_line(0, &rep);
		i = 0;
		while (rep[i])
		{
			quote += (rep[i] == '\'') ? 1 : 0;
			i++;
		}
		if (quote > 1)
			rep = ft_str_remove_c(rep, '\'');
		if (tmp)
			tmp = ft_strjoinfree(tmp, "\n", 1);
		else
			tmp = ft_strdup("\n");
		tmp = ft_strjoinfree(tmp, rep, 3);
	}
	return (tmp);
}
