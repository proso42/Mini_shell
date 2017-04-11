/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:39:00 by proso             #+#    #+#             */
/*   Updated: 2017/03/15 13:55:33 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_utoa(unsigned int value, unsigned int base)
{
	int		rest;
	char	*str;
	char	c[2];
	char	*tmp;

	str = ft_strnew(1);
	c[1] = '\0';
	while (value >= base)
	{
		rest = value % base;
		value /= base;
		c[0] = (rest > 9) ? ((rest - 10) + 'A') : rest + '0';
		tmp = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(c, tmp);
		ft_strdel(&tmp);
	}
	c[0] = (value > 9) ? ((value - 10) + 'A') : value + '0';
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin(c, tmp);
	ft_strdel(&tmp);
	return (str);
}
