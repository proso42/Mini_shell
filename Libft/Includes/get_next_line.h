/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:01:09 by proso             #+#    #+#             */
/*   Updated: 2017/01/12 11:38:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define S (*maillon)->str
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct				s_line
{
	int						fd;
	char					*str;
	struct s_line			*next;
}							t_line;

int							get_next_line(const int fd, char **line);

#endif
