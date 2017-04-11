/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:45:17 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:54:23 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
#include "../Includes/ft_printf.h"

char	*add_zero(char *str, char *mask)
{
	int		i;
	int		zero;
	int		len;
	char	*str_zero;

	i = 0;
	len = ft_strlen(str);
	if (ft_strlen(mask) == 16)
		zero = 11 - len;
	else if (ft_strlen(mask) == 24)
		zero = 16 - len;
	else
		zero = 21 - len;
	if (zero <= 0)
		return (str);
	else
	{
		str_zero = ft_strnew(zero + len);
		ft_memset(str_zero, '0', zero);
		ft_strcat(str_zero, str);
		ft_strdel(&str);
		return (str_zero);
	}
}

char	*apply_mask(char *str, char *mask)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mask[i])
	{
		if (mask[i] != 'X')
			i++;
		else
		{
			mask[i] = str[j];
			j++;
		}
	}
	ft_strdel(&str);
	return (mask);
}

char	*get_mask(int code)
{
	int		len;
	char	*mask;
	char	*str;
	char	*tmp;

	tmp = ft_itoa_base(code, 2);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	if (len > 7 && len <= 11)
		mask = (ft_strdup("110XXXXX10XXXXXX\0"));
	else if (len > 11 && len <= 16)
		mask = (ft_strdup("1110XXXX10XXXXXX10XXXXXX\0"));
	else if (len > 16 && len <= 21)
		mask = (ft_strdup("11110XXX10XXXXXX10XXXXXX10XXXXXX\0"));
	else
		return (NULL);
	str = add_zero(ft_itoa_base(code, 2), mask);
	str = ft_itoa_base(ft_btoi(apply_mask(str, mask)), 16);
	ft_strdel(&mask);
	return (str);
}

char	*loop_uni(char *str, int i, int j, int size)
{
	int		k;
	char	*arg;
	char	*tmp;

	arg = ft_strnew(size);
	tmp = ft_strsub(str, 0, i);
	arg[0] = ft_htoi(tmp);
	ft_strdel(&tmp);
	k = 1;
	while (str[i])
	{
		if ((ft_strlen(str) % 2) != (i % 2))
		{
			tmp = ft_strsub(str, j, i - j + 1);
			arg[k++] = ft_htoi(tmp);
			ft_strdel(&tmp);
			j = i;
		}
		i++;
	}
	ft_strdel(&str);
	return (arg);
}

char	*convert_uni(int code)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	str = get_mask(code);
	i = (ft_strlen(str) % 2) ? 1 : 2;
	j = i;
	if (ft_strlen(str) == 2)
		size = 2;
	else if (ft_strlen(str) < 5)
		size = 3;
	else
		size = 4;
	return (loop_uni(str, i, j, size));
}
