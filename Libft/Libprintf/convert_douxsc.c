/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:35:04 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:52:54 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	convert_percent(t_flag *flags)
{
	flags->arg = ft_strdup("%");
}

void	convert_d(t_flag *flags, t_print *p)
{
	if (flags->modifier == 'H')
		flags->arg = ft_itoa((char)va_arg(p->ap, int));
	else if (flags->modifier == 'h')
		flags->arg = ft_itoa((short)va_arg(p->ap, int));
	else if (flags->modifier == 'l' || flags->modifier == 'L')
		flags->arg = ft_ltoa(va_arg(p->ap, long));
	else
		flags->arg = ft_itoa(va_arg(p->ap, int));
}

void	convert_oux(t_flag *flags, t_print *p)
{
	int		base;

	if (flags->conversion == 'x' || flags->conversion == 'X')
		base = 16;
	else if (flags->conversion == 'o')
		base = 8;
	else
		base = 10;
	if (flags->modifier == 'H')
		flags->arg = ft_utoa((unsigned char)va_arg(p->ap,
								unsigned int), base);
	else if (flags->modifier == 'h')
		flags->arg = ft_utoa((unsigned short)va_arg(p->ap,
								unsigned int), base);
	else if (flags->modifier == 'l' || flags->modifier == 'L')
		flags->arg = ft_lutoa(va_arg(p->ap, unsigned long), base);
	else
		flags->arg = ft_utoa(va_arg(p->ap, unsigned int), base);
	if (flags->conversion == 'x')
		ft_str_down(flags->arg);
}

void	convert_s(t_flag *flags, t_print *p)
{
	char	*tmp;

	if (flags->conversion == 'S' && flags->precision >= 0)
		convert_ls_pre(flags, p);
	else if (flags->conversion == 'S')
		convert_ls(flags, p);
	else
	{
		tmp = va_arg(p->ap, char*);
		if (!tmp)
			flags->arg = ft_strdup("(null)");
		else
			flags->arg = ft_strdup(tmp);
	}
}

void	convert_c(t_flag *flags, t_print *p)
{
	unsigned char	c;

	if (flags->conversion == 'C')
		convert_lc(flags, p);
	else
	{
		c = (unsigned char)va_arg(p->ap, int);
		flags->arg = ft_strnew(1);
		(flags->arg)[0] = (c == 0) ? -1 : c;
		(flags->arg)[1] = '\0';
	}
}
