/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:12:18 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 19:45:57 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_realloc3(char **str)
{
	int		new_size;
	int		i;
	char	*tmp;

	new_size = ft_strlen(*str) + 1;
	tmp = ft_strnew(new_size);
	tmp[0] = 'X';
	i = new_size;
	while (i != 0)
	{
		tmp[i] = (*str)[i - 1];
		i--;
	}
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;
	char	*str;

	str = ft_strnew(1);
	n2 = n;
	if (n < 0)
	{
		n2 *= -1;
		write(1, "-", 1);
	}
	while (n2 >= 10)
	{
		ft_realloc3(&str);
		str[0] = (n2 % 10) + 48;
		n2 /= 10;
	}
	ft_realloc3(&str);
	str[0] = n2 + 48;
	ft_putstr_fd(str, fd);
}
