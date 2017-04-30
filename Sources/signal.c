/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 10:42:33 by proso             #+#    #+#             */
/*   Updated: 2017/04/27 10:42:37 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	ft_kill_process(int sig)
{
	extern pid_t	g_pid;
	char			buf[126];

	if (g_pid > 0)
	{
		(void)sig;
		kill(SIGKILL, g_pid);
		g_pid = -1;
	}
	else if (g_pid != -2)
	{
		(void)sig;
		ft_printf("\n{blue}{bold}%s $> {res}", getcwd(buf, 126));
	}
	else
		(void)sig;
}

void	ft_ignore_sig(int sig)
{
	(void)sig;
}

void	init_signal(void)
{
	signal(SIGINT, ft_kill_process);
	signal(SIGTSTP, ft_ignore_sig);
}
