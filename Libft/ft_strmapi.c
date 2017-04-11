/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:29:49 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:41:35 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				size;
	char			*str;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		str[size] = f(i, s[size]);
		size++;
		i++;
	}
	str[size] = '\0';
	return (str);
}
