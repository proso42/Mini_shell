/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_style.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 21:15:40 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 17:39:15 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		check_text_color(char *str)
{
	if (ft_strnstr(str, "{black}", 7))
		return (30);
	else if (ft_strnstr(str, "{red}", 5))
		return (31);
	else if (ft_strnstr(str, "{green}", 7))
		return (32);
	else if (ft_strnstr(str, "{yellow}", 8))
		return (33);
	else if (ft_strnstr(str, "{blue}", 6))
		return (34);
	else if (ft_strnstr(str, "{magenta}", 9))
		return (35);
	else if (ft_strnstr(str, "{cyan}", 6))
		return (36);
	else if (ft_strnstr(str, "{white}", 7))
		return (37);
	else if (ft_strnstr(str, "{eoc}", 5))
		return (39);
	else
		return (-1);
}

int		check_background_color(char *str)
{
	if (ft_strnstr(str, "{BLACK}", 7))
		return (40);
	else if (ft_strnstr(str, "{RED}", 5))
		return (41);
	else if (ft_strnstr(str, "{GREEN}", 7))
		return (42);
	else if (ft_strnstr(str, "{YELLOW}", 8))
		return (43);
	else if (ft_strnstr(str, "{BLUE}", 6))
		return (44);
	else if (ft_strnstr(str, "{MAGENTA}", 9))
		return (45);
	else if (ft_strnstr(str, "{CYAN}", 6))
		return (46);
	else if (ft_strnstr(str, "{WHITE}", 7))
		return (47);
	else if (ft_strnstr(str, "{EOC}", 5))
		return (49);
	else
		return (-1);
}

int		check_text_style(char *str)
{
	if (ft_strnstr(str, "{res}", 5))
		return (0);
	else if (ft_strnstr(str, "{bold}", 6))
		return (1);
	else if (ft_strnstr(str, "{italic}", 8))
		return (3);
	else if (ft_strnstr(str, "{underline}", 11))
		return (4);
	else if (ft_strnstr(str, "{BOLD}", 6))
		return (22);
	else if (ft_strnstr(str, "{ITALIC}", 8))
		return (23);
	else if (ft_strnstr(str, "{UNDERLINE}", 11))
		return (24);
	else
		return (-1);
}

int		check_brackets(char *str)
{
	int		x;

	if ((x = check_text_color(str)) >= 0)
		return (x);
	else if ((x = check_background_color(str)) >= 0)
		return (x);
	else if ((x = check_text_style(str)) >= 0)
		return (x);
	else
		return (-1);
}
