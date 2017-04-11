/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:49:13 by proso             #+#    #+#             */
/*   Updated: 2016/11/30 10:24:50 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (((char *)big)[i] != '\0')
	{
		if (((char *)big)[i] == little[0])
		{
			j = 0;
			k = i;
			while (((char *)big)[k] == little[j])
			{
				k++;
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
