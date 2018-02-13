# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/02/13 15:00:47 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker

CC		= gcc
# CFLAGS	= -Wall -Werror -Wextra
#DEBUG!!
CFLAGS	= -Wall -Wextra -Og -ggdb

# checker sources
VPATH	+= ./srcs
SRCS	=	checker.c \
			check.c \
			return_instructions.c
# shared sources
VPATH	+= ../shared/srcs/instructions:../shared/srcs/stack:../shared/srcs/print
VPATH	+= ../shared/srcs/free_init
SRCS	+=	free.c \
			init.c
SRCS	+=	instructions.c \
			push.c \
			rev_rotate.c \
			rotate.c \
			swap.c
SRCS	+=	print_functions.c
SRCS	+=	parsing.c \
			return_stack.c

# object files
OBJ_DIR		:=	./obj
OBJECTS		:= $(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS		= $(OBJECTS:.o:.d)
DEPS_FLAGS	= -MMD -MP

# includes
INC_DIR	:=	./includes
INC_DIR	+=	../shared/includes
INC_DIR	+=	../libft/includes
IFLAGS	+= $(foreach d, $(INC_DIR), -I$d)

# libraries
LIB_DIR		:= ../libft
LIBS		:= ft
LIB_FLAGS	:= -L$(LIB_DIR) -l$(LIBS)

# echo output colours
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
NC		= \033[0m

.PHONY: all clean fclean re

all:
	@make -C $(LIB_DIR)/
	@make $(NAME)

$(NAME): $(OBJECTS)
	@echo "[Building ${GREEN}checker${NC}] executable"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:%.c
	@echo "[Building ${GREEN}checker${NC} object: $@]"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@echo "[Cleaning ${GREEN}checker${NC} objects]"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[Cleaning ${GREEN}checker${NC} executable]"
	@/bin/rm -f $(NAME)

re: fclean all

# include all dependicy files
-include $(DEPS)
