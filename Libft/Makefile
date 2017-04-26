# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 14:56:04 by proso             #+#    #+#              #
#    Updated: 2017/04/26 11:25:05 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRC = ft_atoi.c \
	  ft_btoi.c \
	  ft_bzero.c \
	  ft_htoi.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_is_whitespace.c \
	  ft_recursive_factorial.c \
	  ft_recursive_power.c \
	  ft_replace.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_ftoa.c \
	  ft_ltoa.c \
	  ft_ltoa_base.c \
	  ft_utoa.c \
	  ft_lutoa.c \
	  ft_clear_elem.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_push_back.c \
	  ft_push_front.c \
	  ft_remove_list.c \
	  ft_reverse_list.c \
	  ft_dup_list.c \
	  ft_print_list.c \
	  ft_print_list_space.c \
	  ft_list_find.c \
	  ft_list_size.c \
	  ft_list_to_tab.c \
	  ft_get_p_elem.c \
	  ft_get_elem.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putnbr_endl.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putstr_color.c \
	  ft_round.c \
	  ft_str_down.c \
	  ft_str_up.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_del_tab.c \
	  ft_strcdup.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_str_remove_c.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strjoinfree.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrev.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strcsub.c \
	  ft_strsub.c \
	  ft_strsubfree.c \
	  ft_strtrim.c \
	  ft_tab_int_len.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c \
	  ft_printf.c \
	  Libprintf/add_attribute.c \
	  Libprintf/add_prefixe.c \
	  Libprintf/add_prefixe_s.c \
	  Libprintf/add_spec_prefixe.c \
	  Libprintf/change_style.c \
	  Libprintf/check_style.c \
	  Libprintf/convert_douxsc.c \
	  Libprintf/convert_fb.c \
	  Libprintf/convert_lslc.c \
	  Libprintf/flag_overflow.c \
	  Libprintf/get_etoile.c \
	  Libprintf/get_modifier.c \
	  Libprintf/identify_percent.c \
	  Libprintf/unicode.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@echo "$< \x1b[32m\x1b[1m✓\x1b[0m"
	@./p_bar
	@sleep 0.05
	@clear

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\x1b[32m\x1b[1mLibrary created ✓✓✓\x1b[0m"
clean:
	@rm -rf $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\x1b[31m\x1b[1mLibrary deleted ✖\x1b[0m"

low:
	@echo "\x1b[33m\x1b[1mMaking sources... ⏳\x1b[0m"
	@sleep 2

clr:
	@clear

re: clr fclean low all
