/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 08:30:33 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:42:19 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i != len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i != len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
