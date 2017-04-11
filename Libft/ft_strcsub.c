/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:53:42 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 21:02:48 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strcsub(const char *str, char c)
{
	int		i;

	i = 0;
	if (!str || c < 0)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	if (!str[i])
		return (NULL);
	else
	{
		return (ft_strsub(str, i + 1, ft_strlen(str) - i));
	}
}
