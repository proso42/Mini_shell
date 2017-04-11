/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:12:18 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 19:49:42 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_putnbr(int n)
{
	long	n2;
	char	*str;
	char	*c;

	str = ft_strnew(1);
	c = ft_strnew(1);
	n2 = n;
	if (n < 0)
	{
		n2 *= -1;
		write(1, "-", 1);
	}
	while (n2 >= 10)
	{
		c[0] = (n2 % 10) + 48;
		str = ft_strjoinfree(c, str, 2);
		n2 /= 10;
	}
	c[0] = n2 + 48;
	str = ft_strjoinfree(c, str, 2);
	ft_putstr(str);
}
