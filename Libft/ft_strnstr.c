/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:23:21 by proso             #+#    #+#             */
/*   Updated: 2017/03/17 21:47:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	int		i;

	if (((char *)little)[0] == '\0')
		return ((char *)big);
	while ((char)*big != '\0' && len > 0)
	{
		if ((char)*big == ((char *)little)[0])
		{
			i = 0;
			while (((char *)big)[i] == ((char *)little)[i] && len > 0)
			{
				i++;
				len--;
				if (((char *)little)[i] == '\0')
					return ((char *)big);
			}
			len += i;
		}
		len += -1;
		big++;
	}
	return (0);
}
