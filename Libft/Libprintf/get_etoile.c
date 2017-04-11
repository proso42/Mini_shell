/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_etoile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:11:44 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:53:47 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	one_star(t_flag *flags, t_print *p, int i)
{
	while (flags->str_flag[i] != '*')
		i++;
	if (i != 0 && flags->str_flag[i - 1] == '.')
	{
		flags->precision = va_arg(p->ap, int);
		flags->min_fieled = -1;
	}
	else
	{
		flags->min_fieled = va_arg(p->ap, int);
		if (flags->min_fieled < 0)
		{
			flags->min_fieled *= -1;
			flags->moins = 1;
		}
		if (flags->str_flag[i + 1] >= '0' && flags->str_flag[i + 1] <= '9')
			flags->min_fieled = -1;
		flags->precision = -1;
	}
}

void	multiple_stars(t_flag *flags, t_print *p)
{
	int		i;

	i = 0;
	while (flags->str_flag[i] && flags->etoile)
	{
		one_star(flags, p, i);
		i++;
		flags->etoile--;
	}
}

void	get_etoile(t_flag *flags, t_print *p)
{
	int		i;

	i = 0;
	flags->etoile = 0;
	while (flags->str_flag[i])
	{
		if (flags->str_flag[i] == '*')
			flags->etoile++;
		i++;
	}
	if (flags->etoile == 1)
		one_star(flags, p, 0);
	else if (flags->etoile > 1)
		multiple_stars(flags, p);
	else
	{
		flags->min_fieled = -1;
		flags->precision = -1;
	}
}
