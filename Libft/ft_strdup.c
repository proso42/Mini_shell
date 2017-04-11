/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:57:51 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:46:58 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
