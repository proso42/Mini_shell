/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:51:21 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:54:49 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include "Includes/ft_printf.h"

int		show_buff(t_print *p)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	while (p->buff[i])
	{
		if (p->buff[i] == -1)
			write(1, &c, 1);
		else if (p->buff[i] == '\x1b')
			i = apply_style(&(p->buff[i]), p, i);
		else
			write(1, &(p->buff[i]), 1);
		(p->ret)++;
		i++;
	}
	ft_strdel(&(p->buff));
	ft_strdel(&(p->format));
	va_end(p->ap);
	return (p->ret);
}

int		cut(t_print *p, int i)
{
	int		j;
	int		code;

	j = i;
	while ((p->format)[j] && (p->format)[j] != '%' && (p->format)[j] != '{')
		j++;
	p->buff = ft_strjoinfree(p->buff, ft_strsub(p->format, i, j - i), 3);
	if (p->format[j] == '{')
	{
		code = check_brackets(&(p->format[j]));
		if (code < 0)
			p->buff = ft_strjoinfree(p->buff, "{", 1);
		else
		{
			p->buff = ft_strjoinfree(p->buff, change_style(code), 3);
			while (p->format[j] != '}')
				j++;
		}
		return (cut(p, j + 1));
	}
	return (j);
}

int		ft_printf(const char *format, ...)
{
	t_print	p;
	int		i;

	i = 0;
	p.ret = 0;
	p.format = ft_strdup(format);
	p.buff = ft_strnew(0);
	va_start(p.ap, format);
	while (p.format[i])
	{
		i = cut(&p, i);
		if (!(p.format)[i])
			return (show_buff(&p));
		else
			i = identify_percent(&p, i + 1);
	}
	return (show_buff(&p));
}
