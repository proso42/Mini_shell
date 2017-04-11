/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:57:40 by proso             #+#    #+#             */
/*   Updated: 2017/03/17 12:40:13 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_itoa_base(int value, int base)
{
	if (base == 10)
		return (ft_itoa(value));
	else
		return (ft_utoa(value, base));
}
