/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 04:17:44 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:53:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	convert_f(t_flag *flags, t_print *p)
{
	flags->arg = ft_ftoa(va_arg(p->ap, double), flags->precision);
	if (flags->conversion == 'F')
		ft_str_up(flags->arg);
}

void	convert_b(t_flag *flags, t_print *p)
{
	char	*s;
	int		i;

	if (flags->conversion == 'b')
		flags->arg = ft_itoa_base(va_arg(p->ap, int), 2);
	else
	{
		i = 0;
		flags->arg = ft_itoa_base(va_arg(p->ap, int), 2);
		while ((ft_strlen(flags->arg) + i) % 8)
			i++;
		s = ft_strnew(i);
		ft_memset(s, '0', i);
		flags->arg = ft_strjoinfree(s, flags->arg, 3);
	}
}
