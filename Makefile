# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/01/18 16:24:56 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

# checker sources
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH	+= ./srcs/checker
CHECKER_SRCS	=	ft_lstadd.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstnew.c
# push_swap sources
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH	+= ./srcs/push_swap
PUSH_SWAP_SRCS	=	ft_abs32.c

# object files
OBJ_DIR		:=	./obj
OBJECTS		:= $(patsubst %,$(OBJ_DIR)/%,$(CHECKER_SRCS:.c=.o))
OBJECTS		+= $(patsubst %,$(OBJ_DIR)/%,$(PUSH_SWAP_SRCS:.c=.o))
# objects dependencies
DEPS		= $(OBJECTS:.o:.d)
DEPS_FLAGS	= -MMD -MP

# includes
INC_DIR	:=	./includes
IFLAGS	+= $(foreach d, $(INC_DIR), -I$d)
IFLAGS	+= -Ilibft/includes/libft.h

# libraries
LIB_DIR		:= ./libft
LIBS		:= ft
LIB_FLAGS	:= -L$(LIB_DIR) -l$(LIBS)

# echo output colours
CYAN	= \e[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
PURPLE	= \033[1;35m
NC		= \033[0m

.PHONY: all clean fclean re

all:
	@make -C $(LIB_DIR)/
	@make $(PUSH_SWAP)
	@make $(CHECKER)

$(CHECKER): $(OBJECTS)
	@echo "[Building ${RED}executable${NC}]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(PUSH_SWAP): $(OBJECTS)
	@echo "[Building ${RED}executable${NC}]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(IFLAGS)  -o $@ -c $<

clean:
	@echo "[Cleaning ${RED}executables${NC} objects]"
	@make clean -C $(LIB_DIR)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[Cleaning ${RED}executable${NC} binary]"
	@make fclean -C $(LIB_DIR)
	@/bin/rm -rf $(CHECKER)
	@/bin/rm -rf $(PUSH_SWAP)

re: fclean all

# include all dependicy files
-include $(DEPS)
