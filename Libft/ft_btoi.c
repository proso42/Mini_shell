/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:22:56 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 19:00:22 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_btoi(char *str)
{
	int		exp;
	int		i;
	int		nb;

	nb = 0;
	exp = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '1')
			nb += 1 * ft_recursive_power(2, exp);
		exp++;
		i--;
	}
	return (nb);
}
