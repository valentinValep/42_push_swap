# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2023/02/13 14:25:47 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -Iincludes

SOURCES_DIR = src/
OBJECTS_DIR = build/

OBJ = stack.o \
	utils.o \
	main.o \
	stack_utils.o \
	printer.o \
	printer2.o \
	sort.o \
	sort2.o \
	stack_utils2.o \
	simulation.o \
	vector.o \
	sort_b.o \

OBJ := $(addprefix $(OBJECTS_DIR),$(OBJ))

RM = rm -f

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJECTS_DIR) :
	mkdir $(OBJECTS_DIR)
# @TODO rm -g3
$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c | $(OBJECTS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g3

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
