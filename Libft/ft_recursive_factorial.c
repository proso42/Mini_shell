/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:45:13 by proso             #+#    #+#             */
/*   Updated: 2016/12/09 09:24:22 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb > 1)
	{
		nb = ft_recursive_factorial(nb - 1) * nb;
	}
	else
		return (1);
	return (nb);
}
