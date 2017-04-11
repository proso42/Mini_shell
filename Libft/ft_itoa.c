/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:46:20 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 19:19:55 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_itoa(long n)
{
	char		*str;
	char		*c;
	long		rest;
	long		n2;

	n2 = n;
	if (n < 0)
		n2 *= -1;
	str = ft_strnew(1);
	c = ft_strnew(1);
	while (n2 >= 10)
	{
		rest = n2 % 10;
		n2 /= 10;
		c[0] = rest + 48;
		str = ft_strjoinfree(c, str, 2);
	}
	c[0] = n2 + 48;
	str = ft_strjoinfree(c, str, 3);
	if (n < 0)
		str = ft_strjoinfree("-", str, 2);
	return (str);
}
