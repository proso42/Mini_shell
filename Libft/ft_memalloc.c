/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:05:02 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 20:23:37 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char*)malloc(sizeof(char) * size);
	if (!mem)
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
