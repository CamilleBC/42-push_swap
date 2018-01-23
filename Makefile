# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/01/23 16:44:27 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

LIB_DIR			:= ./libft
CHECKER_DIR		:= ./checker
PUSH_SWAP_DIR	:= ./push_swap

# echo output colours
CYAN	= \e[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
PURPLE	= \033[1;35m
NC		= \033[0m

.PHONY: all clean fclean re

all:
	@make -C $(LIB_DIR)/
	@make -C $(CHECKER_DIR)/
	@make -C $(PUSH_SWAP_DIR)/

clean:
	@make clean -C $(LIB_DIR)
	@make clean -C $(CHECKER_DIR)
	@make clean -C $(PUSH_SWAP_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)

re: fclean al
