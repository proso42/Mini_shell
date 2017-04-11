/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:31:23 by proso             #+#    #+#             */
/*   Updated: 2016/11/30 11:35:13 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		len;

	len = 0;
	while ((char)*s)
	{
		len++;
		s++;
	}
	while (len > 0 && (char)*s != c)
	{
		len--;
		s--;
	}
	if ((char)*s == c)
		return ((char *)s);
	else
		return (0);
}
