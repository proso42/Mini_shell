/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:19:43 by proso             #+#    #+#             */
/*   Updated: 2017/03/18 20:04:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*extract_ent(double value)
{
	unsigned long	x;
	char			*str;

	x = (value >= 0.0) ? (unsigned long)value : (unsigned long)-value;
	if (value < 0)
		str = ft_strjoinfree("-", ft_lutoa(x, 10), 2);
	else
		str = ft_lutoa(x, 10);
	return (str);
}

char	*round_str_ent(char **str, double value)
{
	ft_strdel(str);
	value += (value < 0) ? -1 : 1;
	*str = extract_ent(value);
	return (*str);
}

void	round_str(char *str_dec, int i, char **str_ent, double value)
{
	int		stop;

	stop = 0;
	while (!stop)
	{
		str_dec[i] += 1;
		if (str_dec[i] == ':')
		{
			str_dec[i] = '0';
			i--;
		}
		else if (str_dec[i] == '/')
		{
			str_dec[i] = '.';
			stop++;
			*str_ent = round_str_ent(str_ent, value);
		}
		else
			stop++;
	}
}

char	*good_way(double value, int pre)
{
	char	*str;
	char	str_dec[100];
	int		i;
	double	dec;

	if (pre < 0)
		pre = 6;
	str = extract_ent(value);
	str_dec[0] = (pre > 0) ? '.' : '\0';
	dec = (value >= 0) ? value - (unsigned long)value :
			-value - (unsigned long)-value;
	i = 1;
	while (pre > 0)
	{
		dec *= 10;
		str_dec[i] = '0' + (int)dec;
		if ((dec - (int)dec) * 10 >= 5 && pre == 1)
			round_str(str_dec, i, &str, value);
		dec -= (int)dec;
		i++;
		pre--;
	}
	str_dec[i] = '\0';
	str = ft_strjoinfree(str, str_dec, 1);
	return (str);
}

char	*ft_ftoa(double value, int pre)
{
	unsigned long	inf;

	if (value != value)
		return (ft_strdup("nan"));
	inf = *((unsigned long*)&value);
	if (((inf << 1) >> 53) == 0x7ff)
	{
		if ((inf >> 63) != 0)
			return (ft_strdup("-inf"));
		else
			return (ft_strdup("inf"));
	}
	return (good_way(value, pre));
}
