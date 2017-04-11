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

char	*recursive_quote(void)
{
	char	*tmp;
	char	*rep;
	int		stop;

	rep = NULL;
	stop = 0;
	tmp = ft_strnew(0);
	while (!stop)
	{
		ft_putstr("quote> ");
		get_next_line(0, &rep);
		if ((ft_strchr(rep, 39)))
		{
			ft_str_remove_c(rep, 39);
			stop = 1;
		}
		tmp = ft_strjoinfree(tmp, "\n", 1);
		tmp = ft_strjoinfree(tmp, rep, 1);
	}
	return (tmp);
}
