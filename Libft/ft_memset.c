/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:16:41 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:40:24 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *new;

	new = b;
	while (len > 0 && new != '\0')
	{
		*new = (unsigned char)c;
		new++;
		len--;
	}
	return (b);
}
