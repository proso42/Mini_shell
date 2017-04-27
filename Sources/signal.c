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

extern pid_t	pid;

void	ft_kill_process(int sig)
{
	if (pid > 0)
	{
		(void)sig;
		kill(SIGKILL, pid);
		pid = -1;
	}
}

void	ft_ignore_sig(int sig)
{
	(void)sig;
}

void	init_signal(void)
{
	signal(SIGINT, ft_kill_process);
}
