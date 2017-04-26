/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:24:39 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 20:21:34 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		update_str(t_line **maillon, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (S[i] != '\0' && S[i] != '\n')
		i++;
	ft_strdel(&(*line));
	*line = ft_strsub(S, 0, i);
	if (S[i] == '\n')
	{
		tmp = ft_strsub(S, (i + 1), ft_strlen(S) - i + 1);
		ft_strdel(&S);
		S = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (S[i] == '\0')
	{
		ft_strdel(&S);
		if (i == 0)
		{
			(*maillon)->fd = 0;
			return (0);
		}
	}
	return (1);
}

t_line	*create_maillon(const int fd, t_line **list, char *str)
{
	t_line	*maillon;
	t_line	*current;

	current = *list;
	if (!(maillon = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	maillon->fd = fd;
	maillon->str = ft_strdup(str);
	if (!current)
		*list = maillon;
	else
	{
		while (current->next)
			current = current->next;
		current->next = maillon;
	}
	maillon->next = NULL;
	return (maillon);
}

int		read_line(const int fd, t_line **list, t_line **maillon)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;
	int		stop;

	stop = 0;
	str = ft_strnew(1);
	while (!stop && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (fd == 0)
			stop = 1;
	}
	*maillon = create_maillon(fd, list, str);
	ft_strdel(&str);
	return (ret);
}

t_line	*find_fd(const int fd, t_line **list)
{
	t_line *current;

	current = *list;
	if (!current)
		return (NULL);
	while (current)
	{
		if (current->fd == fd && fd != 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*list = NULL;
	t_line			*maillon;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0 || (!line))
		return (-1);
	maillon = list;
	ret = 1;
	*line = ft_strnew(0);
	if (!(maillon = find_fd(fd, &list)))
		ret = read_line(fd, &list, &maillon);
	return ((ret == -1) ? -1 : update_str(&maillon, line));
}
