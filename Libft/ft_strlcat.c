/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 09:40:51 by proso             #+#    #+#             */
/*   Updated: 2017/01/03 09:24:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

size_t		ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t		dst_size;
	size_t		src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	else
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
	return (dst_size + src_size);
}
