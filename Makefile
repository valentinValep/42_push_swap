# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2023/01/16 19:34:35 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

SRC = stack.c \
	utils.c \
	main.c \
	stack_group.c \
	stack_utils.c

OBJ = stack.o \
	utils.o \
	main.o \
	stack_group.o \
	stack_utils.o

RM = rm -f

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
# @TODO RM -g3
%.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g3

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
