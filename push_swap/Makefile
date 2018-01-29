# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/01/29 21:03:58 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra

# push_swap sources
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH	+= ./srcs:./srcs/algorithms:./srcs/instructions:./srcs/stack_manipulation
VPATH	+= ../shared/srcs/instructions:../shared/srcs/stack:../shared/srcs/print
SRCS	=	push_swap.c
SRCS	+=	algorithms.c \
			insertion_sort.c \
			nearly_sorted.c \
			sort_three.c
SRCS	+=	optimise_instructions.c
SRCS	+=	stack_checks.c \
			stack_conversion.c \
			stack_move.c \
			stack_search.c
SRCS	+=	instructions.c \
			instruction_set.c
SRCS	+=	stack.c \
			list_manipulation.c \
			stack_manipulation.c \
			stack_parsing.c
SRCS	+=	print_functions.c

# object files
OBJ_DIR		:=	./obj
OBJECTS		+= $(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
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
	@echo "[Building ${RED}push_swap${NC}]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)
	#@mv $(NAME) ../

$(OBJ_DIR)/%.o:%.c
	@echo "[Building ${RED}push_swap${NC} object: $@]"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@echo "[Cleaning ${RED}push_swap${NC} objects]"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[Cleaning ${RED}push_swap${NC} binary]"
	@/bin/rm -rf $(NAME)

re: fclean all

# include all dependicy files
-include $(DEPS)
