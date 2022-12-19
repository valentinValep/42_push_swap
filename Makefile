# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/19 13:26:27 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

SRC = push_swap.c \
	push_swap2.c \
	push_swap3.c \
	utils.c \
	stack.c \
	main.c

OBJ = push_swap.o \
	push_swap2.o \
	push_swap3.o \
	utils.o \
	stack.o \
	main.o

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
