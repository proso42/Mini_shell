/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:09:00 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:42:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int		i;
	size_t	x;

	i = 0;
	x = n;
	while (s1[i] != '\0' && x > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		x--;
	}
	i = 0;
	x = n;
	while (s2[i] != '\0' && x > 0)
	{
		if (s2[i] != s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		x--;
	}
	return (0);
}
