/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 09:51:56 by proso             #+#    #+#             */
/*   Updated: 2017/03/06 13:08:35 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strsubfree(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (!(str = ft_strnew(len)))
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	ft_strdel((char**)&s);
	return (str);
}
