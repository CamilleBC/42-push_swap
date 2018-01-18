# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#              #
#    Updated: 2018/01/18 15:56:39 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

# libft sources
# we use the VPATH variable which causes MAKE to look for sources in all those
# directories
VPATH	+= ./srcs/math:./srcs/memory:./srcs/lists:./srcs/strings
SRCS	=	ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c
SRCS 	+=	ft_abs32.c


# object files
OBJ_DIR		:=	./obj
OBJECTS		:= $(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS		= $(OBJECTS:.o:.d)
DEPS_FLAGS	= -MMD -MP

# includes
INC_DIR	:=	./includes
IFLAGS	+= $(foreach d, $(INC_DIR), -I$d)

# echo output colours
CYAN	= \e[1;36m
RED		= \033[1;31m
WHITE	= \033[1;37m
PURPLE	= \033[1;35m
NC		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "[Building ${PURPLE}library${NC}]"
	@ar rcs $(NAME) $(OBJECTS)


$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(IFLAGS)  -o $@ -c $<

clean:
	@echo "[Cleaning ${PURPLE}lib${NC} objects]"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[Cleaning ${PURPLE}lib${NC} binary]"
	@/bin/rm -rf $(NAME)

re: fclean all

# include all dependicy files
-include $(DEPS)
