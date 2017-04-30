/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:13:18 by proso             #+#    #+#             */
/*   Updated: 2017/03/15 14:00:15 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int mode)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
	{
		str = (s1) ? ft_strdup(s1) : ft_strdup(s2);
		((mode == 1 || mode > 2) ? ft_strdel((char**)&s1) : 0);
		if (mode >= 2)
			ft_strdel((char**)&s2);
		return (str);
	}
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	((mode == 1 || mode > 2) ? ft_strdel((char**)&s1) : 0);
	if (mode >= 2)
		ft_strdel((char**)&s2);
	return (str);
}
