/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:22:06 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:43:31 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int	is_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\f' || c == '\v'
			|| c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_count_whitespaces(char const *s)
{
	int		size;

	size = 0;
	while (s[size] != '\0')
		size++;
	while (is_whitespace(*s))
	{
		size--;
		s++;
	}
	if (*s == '\0')
		return (size);
	while (*s != '\0')
		s++;
	if (*s == '\0')
		s--;
	while (is_whitespace(*s))
	{
		size--;
		s--;
	}
	return (size + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		stop;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	j = 0;
	str = (char*)malloc(sizeof(char) * ft_count_whitespaces(s));
	if (!str)
		return (NULL);
	while (is_whitespace(s[i]))
		i--;
	stop = i;
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	while (s[i] != '\0' && i <= stop)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
