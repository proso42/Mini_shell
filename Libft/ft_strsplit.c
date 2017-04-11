/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:51:04 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 10:42:46 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s != '\0')
			{
				tab[i][j] = *s;
				j++;
				s++;
			}
			tab[i][j] = '\0';
			j = 0;
			i++;
		}
	}
}

static char	**ft_alloc(char **tab, char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s != '\0')
			{
				s++;
				n++;
			}
			if (!(tab[i] = (char*)malloc(sizeof(char) * n)))
				return (NULL);
			n = 0;
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

static int	count_word(char const *s, char c)
{
	int		n;

	if (*s == c)
		s++;
	n = 0;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
		n++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = (char**)malloc(sizeof(char*) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_alloc(tab, s, c);
	ft_fill_tab(tab, s, c);
	return (tab);
}
