/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:02:56 by proso             #+#    #+#             */
/*   Updated: 2017/03/15 13:55:18 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_ltoa_base(long value, long base)
{
	if (base == 10)
		return (ft_ltoa(value));
	else
		return (ft_lutoa(value, base));
}
