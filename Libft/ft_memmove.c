/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:59:02 by proso             #+#    #+#             */
/*   Updated: 2017/01/11 12:00:09 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	i = 0;
	dst2 = dst;
	src2 = (void *)src;
	if ((void *)src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst2[i] = src2[i];
		}
	}
	else
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
