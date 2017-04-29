# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 12:07:31 by proso             #+#    #+#              #
#    Updated: 2017/04/29 15:35:17 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = Sources/builtin.c \
      Sources/check_path_error.c \
	  Sources/check_valid_cmd.c \
	  Sources/cmd_cd.c \
	  Sources/cmd_echo.c \
	  Sources/cmd_env.c \
	  Sources/cmd_set_env.c \
	  Sources/cmd_unset_env.c \
	  Sources/cmd.c \
	  Sources/exec.c \
	  Sources/get_env_var.c \
	  Sources/get_pwd.c \
	  Sources/init.c \
	  Sources/main.c \
	  Sources/recursive_dbl_quote.c \
	  Sources/recursive_quote.c \
	  Sources/signal.c \
	  Sources/use_dbl_quote.c \
	  Sources/use_dollard.c \
	  Sources/use_quote.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = Includes/mini_shell.h

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -I./$(LIB) -o $@ -c $<
	@echo "$< \x1b[32m\x1b[1m✓\x1b[0m"
	@Sources/p_bar_shell
	@sleep 0.05
	@clear

make_lib:
	@make -C Libft/
	@echo "\x1b[33m\x1b[1mMaking sources... ⏳\x1b[0m"
	@sleep 2

$(NAME): make_lib $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\x1b[32m\x1b[1mExecutable sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -rf $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -rf $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

re: fclean all
