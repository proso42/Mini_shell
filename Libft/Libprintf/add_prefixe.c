/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefixe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:45:14 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:51:44 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	add_min_fieled(t_flag *flags)
{
	int		size;
	char	*s;

	size = flags->min_fieled - ft_strlen(flags->arg);
	if (size > 0)
	{
		s = ft_strnew(size);
		(flags->zero) ? ft_memset(s, '0', size) : ft_memset(s, ' ', size);
		if (flags->moins)
			flags->arg = ft_strjoinfree(flags->arg, s, 3);
		else if (!flags->zero)
			flags->arg = ft_strjoinfree(s, flags->arg, 3);
		else if (flags->arg[0] == '-')
		{
			flags->arg = ft_strjoinfree(s, flags->arg, 3);
			ft_replace(flags->arg, '-', '0');
			flags->arg[0] = '-';
		}
		else
			flags->arg = ft_strjoinfree(s, flags->arg, 3);
	}
}

void	add_precision(t_flag *flags)
{
	int		n;
	int		neg;
	char	*s;

	if (flags->arg[0] == '-' && !(ft_strchr("sS", flags->conversion)))
		flags->precision++;
	if (flags->conversion == 's' || flags->conversion == 'S')
		add_precision_s(flags);
	else if (flags->precision == 0 && flags->conversion != '%')
		flags->arg = ft_strnew(0);
	else if ((int)ft_strlen(flags->arg) < flags->precision)
	{
		neg = 0;
		if (flags->arg[0] == '-')
		{
			(flags->arg)[0] = '0';
			neg = 1;
		}
		n = flags->precision - ft_strlen(flags->arg);
		s = (neg == 1) ? ft_strnew(n + 1) : ft_strnew(n);
		neg == 1 ? ft_memset(s, '0', n) : ft_memset(s, '0', n);
		flags->arg = ft_strjoinfree(s, flags->arg, 3);
		if (neg == 1)
			(flags->arg)[0] = '-';
	}
}

void	add_plus_or_space(t_flag *flags)
{
	char	*c;

	if ((flags->space || flags->plus) && (flags->arg)[0] != '-')
	{
		if (flags->plus)
			c = ft_strdup("+");
		else if (flags->space)
			c = ft_strdup(" ");
		else
			c = ft_strnew(0);
		if (c)
			flags->arg = ft_strjoinfree(c, flags->arg, 3);
	}
}

void	add_diese(t_flag *flags)
{
	char	*c;

	if ((flags->arg)[0] == '0' && (flags->arg)[1] == '\0' && !flags->addr)
	{
	}
	else
	{
		if (flags->conversion == 'o')
			c = ft_strdup("0");
		else if (flags->conversion == 'x')
			c = ft_strdup("0x");
		else if (flags->conversion == 'X')
			c = ft_strdup("0X");
		else
			c = ft_strnew(0);
		if (c && !((flags->conversion == 'o') && flags->arg[0] == '0'))
			flags->arg = ft_strjoinfree(c, flags->arg, 3);
	}
}

void	add_prefixe(t_flag *flags)
{
	if (flags->conversion == 'o' && !flags->precision && flags->diese)
		add_prefixe_spc_o(flags);
	else if (ft_strchr("oxX", flags->conversion))
		add_prefixe_xo(flags);
	else if (ft_strchr("du%cCkfFsS", flags->conversion))
		add_prefixe_ducf(flags);
}
