/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spec_prefixe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:44:53 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:52:17 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	add_prefixe_spc_o(t_flag *flags)
{
	if (flags->zero)
	{
		ft_strdel(&(flags->arg));
		flags->arg = ft_strnew(1);
		flags->arg[0] = '0';
	}
	else
	{
		ft_strdel(&(flags->arg));
		flags->arg = ft_strnew(1);
		flags->arg[0] = '0';
		if (flags->min_fieled > 1)
			add_min_fieled(flags);
	}
}

void	add_prefixe_xo(t_flag *flags)
{
	if (flags->precision >= 0)
		add_precision(flags);
	if (flags->zero)
	{
		if (flags->diese && flags->precision != 0 && flags->conversion == 'o')
			flags->min_fieled -= 1;
		else if (flags->diese && flags->precision != 0)
			flags->min_fieled -= 2;
		if (flags->min_fieled > 0)
			add_min_fieled(flags);
		if (flags->diese && flags->precision != 0)
			add_diese(flags);
	}
	else
	{
		if (flags->diese && flags->precision != 0)
			add_diese(flags);
		else if (flags->diese && !flags->precision && flags->addr)
			add_diese(flags);
		if (flags->min_fieled > 0)
			add_min_fieled(flags);
	}
}

void	add_prefixe_ducf(t_flag *flags)
{
	if (flags->conversion == 'd' && flags->precision > 0)
		add_precision(flags);
	else if (flags->conversion == 'd' && flags->precision == 0
				&& ft_atoi(flags->arg) == 0)
		add_precision(flags);
	else if (!(ft_strchr("dfF", flags->conversion)) && flags->precision >= 0)
		add_precision(flags);
	if (!flags->zero)
	{
		if (flags->plus || flags->space)
			add_plus_or_space(flags);
		if (flags->min_fieled > 0)
			add_min_fieled(flags);
	}
	else
	{
		if ((flags->plus || flags->space) && flags->conversion == 'd'
				&& ft_atoi(flags->arg) >= 0)
			flags->min_fieled -= 1;
		if (flags->min_fieled > 0)
			add_min_fieled(flags);
		if (flags->plus || flags->space)
			add_plus_or_space(flags);
	}
}
