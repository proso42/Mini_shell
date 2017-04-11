/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:24:15 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 11:24:33 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char    *ft_str_remove_c(char *str, char c)
{
    int     i;
    int     j;
    char    *tmp;

    i = 0;
    j = 0;
    tmp = ft_strnew(ft_strlen(str));
    if (c > 0)
    {
        while (str[i])
        {
            if (str[i] != c)
            {
                tmp[j] = str[i];
                j++;
            }
            i++;
        }
        ft_strdel(&str);
        str = ft_strdup(tmp);
        ft_strdel(&tmp);
    }
    return (str);
}
