/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 19:18:11 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 13:51:05 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/mini_shell.h"

void	print_prompt(void)
{
	char	buf[126];

	ft_printf("{blue}{bold}%s $> {res}", getcwd(buf, 126));
}

void	print_entry(void)
{
	ft_putstr_color("+---------------------------+\n", C_GREEN);
	ft_putstr_color("|                           |\n", C_GREEN);
	ft_putstr_color("|     Bienvenue dans le     |\n", C_GREEN);
	ft_putstr_color("|         MiniShell         |\n", C_GREEN);
	ft_putstr_color("|                           |\n", C_GREEN);
	ft_putstr_color("+---------------------------+\n", C_GREEN);
}

int		main(void)
{
	t_info	info;
	char	*cmd;
	int		i;

	info.env_var_list = init_env();
	info.cmd_list = init_cmd();
	i = 0;
	print_entry();
	while (1)
	{
		cmd = NULL;
		print_prompt();
		if ((get_next_line(0, &cmd)))
			get_cmd(&info, cmd);
		else
			write(1, "\n", 1);
		ft_strdel(&cmd);
	}
	return (0);
}
