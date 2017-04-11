/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:56:20 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:54:00 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	analyse_modifier2(int *z, int *j, t_flag *flags)
{
	int		i;

	i = 0;
	while ((flags->str_flag)[i])
	{
		if ((flags->str_flag)[i] == 'z')
			(*z)++;
		else if ((flags->str_flag)[i] == 'j')
			(*j)++;
		i++;
	}
}

void	analyse_modifier(int *l, int *h, t_flag *flags)
{
	int		i;

	i = 0;
	while ((flags->str_flag)[i])
	{
		if ((flags->str_flag)[i] == 'l')
			(*l)++;
		else if ((flags->str_flag)[i] == 'h')
			(*h)++;
		i++;
	}
}

void	init_variable(int *l, int *h, int *z, int *j)
{
	*l = 0;
	*h = 0;
	*z = 0;
	*j = 0;
}

void	get_modifier(t_flag *flags)
{
	int		l;
	int		h;
	int		z;
	int		j;

	init_variable(&l, &h, &z, &j);
	analyse_modifier(&l, &h, flags);
	analyse_modifier2(&j, &z, flags);
	if (l == 1 || l > 2)
		flags->modifier = 'l';
	else if (l == 2 || z > 0 || j > 0)
		flags->modifier = 'L';
	else if ((h == 1 || h > 2) && !l && !z && !j)
		flags->modifier = 'h';
	else if (h == 2 && !l && !z && !j)
		flags->modifier = 'H';
	else
		flags->modifier = 'k';
}
