/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_local_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 02:52:18 by proso             #+#    #+#             */
/*   Updated: 2017/04/30 02:52:20 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

int		check_local_path(char *path)
{
	int		i;
	int		ok;

	i = (path[1] == '/') ? 2 : 1;
	ok = 0;
	if (path[i] == '/')
	{
		path[i] = '\0';
		ok = 1;
	}
	if ((access(path, F_OK)))
		return (-1);
	if (ok)
		path[i] = '/';
	return (0);
}
