/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:27:04 by proso             #+#    #+#             */
/*   Updated: 2017/04/10 18:16:38 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define C_RED 1
# define C_GREEN 2
# define C_YELLOW 3
# define C_BLUE 4
# define C_MAGENTA 5
# define C_CYAN 6
# define C_WHITE 7

typedef	struct		s_list
{
	void			*data;
	int				size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char const *str);
int					ft_btoi(char *str);
void				ft_bzero(void *s, size_t n);
int					ft_htoi(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_recursive_factorial(int nb);
int					ft_recursive_power(int nb, int power);
char				*ft_replace(char *str, char old, char new);
char				*ft_itoa(long n);
char				*ft_itoa_base(int value, int base);
char				*ft_ltoa(long long n);
char				*ft_ltoa_base(long value, long base);
char				*ft_ftoa(double value, int pre);
char				*ft_utoa(unsigned int value, unsigned int base);
char				*ft_lutoa(unsigned long value, unsigned long base);
void				ft_fill_str(int nb_char, int n, char *str);
void				ft_clear_elem(t_list **begin_list, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_push_back(t_list **begin_list, void *str);
void    			ft_push_front(t_list **begin_list, char *str);
void				ft_remove_list(t_list **begin_list);
void				ft_reverse_list(t_list **begin_list);
t_list				*ft_dup_list(t_list *begin_list);
void				ft_print_list(t_list *begin_list);
void				ft_print_list_space(t_list *begin_list);
t_list				*ft_list_find(t_list *begin_list, char *str);
int					ft_list_size(t_list *begin_list);
char    			*ft_get_elem(t_list *begin_list, int i);
t_list      		*ft_get_p_elem(t_list *begin_list, int i);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				ft_memdel(void **app);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_endl(int n);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr_color(char *str, int color);
int					ft_round(double x);
void				ft_str_down(char *str);
void				ft_str_up(char *str);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strchr(char const *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char const *src);
void				ft_strdel(char **as);
char				*ft_strcdup(char const *str, char c);
char				*ft_strdup(char const *s1);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_str_remove_c(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char const *s1, char const *s2, int mode);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
size_t				ft_strlen(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char const *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, char const *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(char const *big, char const *little,
					size_t len);
char				*ft_strrchr(char const *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *big, char const *little);
char				*ft_strcsub(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubfree(char const *s,
										unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tab_int_len(int *tab_int);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				progress_bar(void);

#endif
