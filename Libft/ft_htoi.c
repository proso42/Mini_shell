/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:46:58 by proso             #+#    #+#             */
/*   Updated: 2017/03/15 15:41:54 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_htoi(char *str)
{
	int		exp;
	int		i;
	int		nb;

	nb = 0;
	exp = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb += (str[i] - 48) * ft_recursive_power(16, exp);
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb += (str[i] - 55) * ft_recursive_power(16, exp);
		else
			nb += (str[i] - 87) * ft_recursive_power(16, exp);
		i--;
		exp++;
	}
	return (nb);
}
