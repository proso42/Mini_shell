/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:51:41 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:53:33 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	invalid_conversion(t_flag *flags)
{
	flags->precision = -1;
	flags->plus = 0;
	flags->diese = 0;
	flags->space = 0;
}

void	undefined_modifier(t_flag *flags)
{
	if (ft_strchr("sc", flags->conversion) && flags->modifier != 'l')
		flags->modifier = 'k';
	if (ft_strchr("sc", flags->conversion) && flags->modifier == 'l')
	{
		flags->modifier = 'k';
		flags->conversion -= 32;
	}
	if (ft_strchr("SC", flags->conversion))
		flags->modifier = 'k';
	if (ft_strchr("douxX", flags->conversion) &&
				ft_strchr("zj", flags->modifier))
		flags->modifier = 'L';
}

void	conversion_overflow(t_flag *flags)
{
	if (flags->conversion == 'c' || flags->conversion == 'C')
		flags->precision = -1;
	if (flags->conversion < 97 && !(ft_strchr("FX%BCS", flags->conversion)))
	{
		flags->conversion += 32;
		flags->modifier = 'l';
	}
	if (flags->conversion == 'p')
	{
		flags->conversion = 'x';
		flags->diese = 1;
		flags->addr = 1;
		flags->modifier = 'l';
		flags->arg = NULL;
	}
	if (flags->conversion == 'i')
		flags->conversion = 'd';
	if (!(ft_strchr("dfF", flags->conversion)) && (flags->space || flags->plus))
	{
		flags->space = 0;
		flags->plus = 0;
	}
	if (flags->conversion == 'k')
		invalid_conversion(flags);
}

void	flag_overflow(t_flag *flags)
{
	char	c;

	conversion_overflow(flags);
	c = flags->conversion;
	if (flags->conversion != 'd' && flags->plus)
		flags->plus = 0;
	if (flags->moins && flags->zero)
		flags->zero = 0;
	if (flags->plus && flags->space)
		flags->space = 0;
	if (flags->precision >= 0 && (ft_strchr("diouxX", c)))
		flags->zero = 0;
	if (c != 'o' && c != 'x' && c != 'X')
		flags->diese = 0;
	if (!flags->precision && flags->conversion == 'o' && flags->diese)
		flags->precision = -1;
	if (c == '%')
		flags->precision = -1;
	undefined_modifier(flags);
}
