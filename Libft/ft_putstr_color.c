/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 17:36:14 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 17:48:18 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_putstr_color(char *str, int color)
{
	ft_putstr("\x1b[3");
	ft_putchar(48 + color);
	ft_putchar('m');
	ft_putstr("\x1b[1m");
	ft_putstr(str);
	ft_putstr("\x1b[0m");
}
