/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:30:02 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 20:26:47 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char *dst2;
	char *src2;
	char c2;

	dst2 = dst;
	src2 = (char*)src;
	c2 = c + 0;
	while (n > 0)
	{
		*dst2 = *src2;
		if (*src2 == c2)
			return (dst2 + 1);
		dst2++;
		src2++;
		n--;
	}
	return (0);
}
