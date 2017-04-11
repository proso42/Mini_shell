/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_style.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 22:07:48 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:58:02 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

char	*change_style(int x)
{
	char	*str;
	char	*code;

	str = ft_strnew(5);
	code = ft_itoa(x);
	ft_strcat(str, "\x1b[");
	ft_strcat(str, code);
	ft_strcat(str, "m");
	ft_strdel(&code);
	return (ft_strdup(str));
}

int		check_code(char *str)
{
	if (ft_strlen(str) < 5)
		return (0);
	else if (*str != '\x1b')
		return (0);
	else if (*(str + 1) != '[')
		return (0);
	else if (*(str + 2) != '0' && *(str + 2) != '3' && *(str + 2) != '4')
		return (0);
	else if (*(str + 2) == '0' && (*(str + 3) < 2 || *(str + 3) > 4))
		return (0);
	else if (*(str + 3) > 7)
		return (0);
	else if (*(str + 4) != 'm')
		return (0);
	else
		return (1);
}

int		apply_style(char *str, t_print *p, int i)
{
	int		code;
	char	*sub;

	if (!(code = check_code(str)))
	{
		write(1, "\x1b", 1);
		return (i);
	}
	sub = ft_strsub(str, 0, 5);
	ft_putstr(sub);
	(p->ret)--;
	ft_strdel(&sub);
	return (i + 4);
}
