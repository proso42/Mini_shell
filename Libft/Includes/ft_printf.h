/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:34:12 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 20:22:16 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flag
{
	int			plus;
	int			moins;
	int			zero;
	int			diese;
	int			etoile;
	int			min_fieled;
	int			precision;
	int			space;
	int			addr;
	int			error;
	char		conversion;
	char		modifier;
	char		*str_flag;
	char		*arg;
}				t_flag;

typedef struct	s_print
{
	char		*buff;
	char		*format;
	va_list		ap;
	int			ret;
}				t_print;

int				identify_percent(t_print *p, int i);
int				check_conversion(char c);
int				ft_printf(const char *format, ...);
int				show_buff(t_print *p);
int				apply_style(char *str, t_print *p, int i);
int				check_brackets(char *str);
char			*convert_uni(int code);
char			*change_style(int x);
void			get_modifier(t_flag *flags);
void			get_etoile(t_flag *flags, t_print *p);
void			flag_overflow(t_flag *flags);
void			add_attribute(t_flag *flags, t_print *p);
void			add_prefixe_xo(t_flag *flags);
void			add_prefixe_ducf(t_flag *flags);
void			add_prefixe_spc_o(t_flag *flags);
void			add_diese(t_flag *flags);
void			add_plus_or_space(t_flag *flags);
void			add_precision(t_flag *flags);
void			add_min_fieled(t_flag *flags);
void			convert_percent(t_flag *flags);
void			convert_d(t_flag *flags, t_print *p);
void			convert_oux(t_flag *flags, t_print *p);
void			convert_s(t_flag *flags, t_print *p);
void			convert_c(t_flag *flags, t_print *p);
void			convert_f(t_flag *flags, t_print *p);
void			convert_b(t_flag *flags, t_print *p);
void			convert_lc(t_flag *flags, t_print *p);
void			convert_ls(t_flag *flags, t_print *p);
void			convert_ls_pre(t_flag *flags, t_print *p);
void			convert_error(t_flag *flags);
void			add_prefixe(t_flag *flags);
void			add_precision_s(t_flag *flags);
void			add_min_fieled_s(t_flag *flags);

#endif
