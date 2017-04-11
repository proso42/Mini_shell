/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:46:49 by proso             #+#    #+#             */
/*   Updated: 2017/01/19 11:17:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		j;

	rev = ft_strnew(ft_strlen(str));
	i = 0;
	j = ft_strlen(str);
	while (j > 0)
	{
		rev[i] = str[j - 1];
		i++;
		j--;
	}
	ft_strclr(str);
	ft_strcpy(str, rev);
	ft_strdel(&rev);
	return (str);
}
