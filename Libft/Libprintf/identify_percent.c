/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:12:57 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:54:13 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

void	get_conversion(t_flag *flags)
{
	int		i;
	int		stop;

	i = 0;
	stop = 0;
	flags->conversion = 'k';
	while (!stop && (flags->str_flag)[i])
	{
		if (ft_strchr("dDsSoOuUxXp%icCfFbB", (flags->str_flag)[i]))
		{
			flags->conversion = (flags->str_flag)[i];
			stop = 1;
			i++;
		}
		else if (ft_strchr(" *#+-lhzj.0123456789", (flags->str_flag)[i]))
			i++;
		else
			stop = 1;
	}
	if (flags->conversion == 'k')
		flags->error = flags->str_flag[i];
}

void	get_precision(t_flag *flags)
{
	int		i;

	i = 0;
	while (flags->str_flag[i] != '.' && flags->str_flag[i])
		i++;
	if (!flags->str_flag[i])
		flags->precision = -1;
	else if ((flags->str_flag)[i + 1] == flags->conversion)
		flags->precision = 0;
	else
		flags->precision = ft_atoi(&((flags->str_flag)[i + 1]));
}

void	get_min_fieled(t_flag *flags)
{
	int		i;
	char	*s;

	s = flags->str_flag;
	i = 0;
	while ((s[i] < '1' || s[i] > '9') && s[i] && s[i] != '.')
		i++;
	if (!s[i] || s[i] == '.')
		flags->min_fieled = -1;
	else
	{
		if (s[i] == '0' && (s[i + 1] < '0' || s[i + 1] > '9'))
			flags->min_fieled = -1;
		else
			flags->min_fieled = ft_atoi(&((flags->str_flag)[i]));
	}
}

void	get_other_flags(t_flag *flags)
{
	int		i;
	int		first;

	i = 0;
	first = 0;
	flags->plus = 0;
	flags->moins = 0;
	flags->zero = 0;
	flags->space = 0;
	while (flags->str_flag[i])
	{
		if (flags->str_flag[i] > '0' && flags->str_flag[i] <= '9')
			first = 1;
		else if (flags->str_flag[i] == ' ')
			flags->space = 1;
		else if (flags->str_flag[i] == '#')
			flags->diese = 1;
		else if (flags->str_flag[i] == '+')
			flags->plus = 1;
		else if (flags->str_flag[i] == '-')
			flags->moins = 1;
		else if (flags->str_flag[i] == '0' && !first)
			flags->zero = 1;
		i++;
	}
}

int		identify_percent(t_print *p, int i)
{
	t_flag	flags;
	int		j;

	if (p->format[i] == '\0')
		return (i);
	j = i;
	while ((p->format)[j] && (ft_strchr(" *#+-lhzj.0123456789",
									((p->format)[j]))))
		j++;
	flags.str_flag = ft_strsub(p->format, i, (j - i + 1));
	flags.addr = 0;
	flags.diese = 0;
	get_other_flags(&flags);
	get_etoile(&flags, p);
	if (flags.min_fieled == -1)
		get_min_fieled(&flags);
	if (flags.precision == -1)
		get_precision(&flags);
	get_conversion(&flags);
	get_modifier(&flags);
	flag_overflow(&flags);
	add_attribute(&flags, p);
	ft_strdel(&(flags.str_flag));
	return (j + 1);
}
