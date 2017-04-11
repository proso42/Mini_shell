/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 21:14:18 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 21:17:42 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strcdup(const char *str, char c)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str || c < 0)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	if (!str[i])
		return (ft_strdup(str));
	else
	{
		str2 = ft_strnew(i);
		ft_strncpy(str2, str, i);
		return (str2);
	}
}
