/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:00:54 by proso             #+#    #+#             */
/*   Updated: 2017/03/17 19:37:33 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
