/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:29:40 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:42:33 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	return (1);
}
