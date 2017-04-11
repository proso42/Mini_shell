/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:50:39 by proso             #+#    #+#             */
/*   Updated: 2017/04/08 12:54:17 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "../Libft/Includes/libft.h"

typedef struct	s_env
{
	char		*env_complete;
	char		*env_name;
	char		*env_value;
}				t_env;

typedef struct  s_info
{
    t_list      *env_var_list;
    t_list      *cmd_list;
}               t_info;

t_list	*init_env(void);
t_list  *init_cmd(void);
void		cmd_env(t_list *env_var_list);
int     cmd_set_env(t_list **env_var_list, t_list *arg_cmd);
int			cmd_unset_env(t_list **env_var_list, t_list *arg_cmd);
void    cmd_echo(t_list *env_var_list, t_list *arg_cmd);
int     get_cmd(t_info *info, char *cmd);
char    *get_env_var(t_list *env_var_list, char *name);
int     exec_cmd(t_list *arg_cmd, t_list *env_var_list);
char		*use_dol(int *i, char *arg, t_list *env_var_list);
char		*use_quote(char *arg, int *i);
char    *recursive_quote(void);
//char		*use_dbl_quote(char *arg, t_list *env_var_list);
//char		*sub_var(char *str, t_list *env_var_list);

#endif
