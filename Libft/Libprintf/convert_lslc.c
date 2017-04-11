/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lslc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:10:48 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:53:23 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	convert_lc(t_flag *flags, t_print *p)
{
	int		c;
	char	s[2];

	s[1] = '\0';
	c = va_arg(p->ap, int);
	if (c <= 127)
	{
		s[0] = (c == 0) ? -1 : c;
		flags->arg = ft_strdup(s);
	}
	else
		flags->arg = convert_uni(c);
}

char	*get_char(int char_uni)
{
	char	*ctrl;

	if (char_uni <= 127)
	{
		ctrl = ft_strnew(1);
		ctrl[0] = char_uni;
	}
	else
		ctrl = convert_uni(char_uni);
	return (ctrl);
}

void	convert_ls_pre(t_flag *flags, t_print *p)
{
	char	*tmp;
	char	*ctrl;
	int		*tab_uni;
	int		stop;

	stop = (flags->precision == 0) ? 1 : 0;
	tab_uni = va_arg(p->ap, int*);
	flags->arg = ft_strnew(0);
	while (*tab_uni && !stop)
	{
		tmp = (flags->arg) ? ft_strdup(flags->arg) : ft_strnew(0);
		ctrl = get_char(*tab_uni);
		if ((int)(ft_strlen(tmp) + ft_strlen(ctrl)) > flags->precision)
			stop = 1;
		else
		{
			ft_strdel(&(flags->arg));
			flags->arg = ft_strjoinfree(tmp, ctrl, 3);
		}
		tab_uni++;
		if ((int)ft_strlen(flags->arg) == flags->precision)
			stop = 1;
	}
	if (flags->precision == 0)
		flags->arg = ft_strnew(0);
}

void	convert_ls(t_flag *flags, t_print *p)
{
	int		*tab_uni;
	char	c[2];
	int		i;

	i = 0;
	tab_uni = va_arg(p->ap, int*);
	if (!tab_uni)
		flags->arg = ft_strdup("(null)");
	else
	{
		c[1] = '\0';
		flags->arg = ft_strnew(0);
		while (tab_uni[i])
		{
			if (tab_uni[i] <= 127)
			{
				c[0] = tab_uni[i];
				flags->arg = ft_strjoinfree(flags->arg, c, 1);
			}
			else
				flags->arg = ft_strjoinfree(flags->arg,
						convert_uni(tab_uni[i]), 3);
			i++;
		}
	}
}
