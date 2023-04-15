# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2023/04/15 18:46:51 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Werror -Wextra

LIRARIES_DIR = lib/

INCLUDES = -Iincludes -I$(LIRARIES_DIR)libft

LIRARIES = -L$(LIRARIES_DIR)libft -lft

SOURCES_DIR = src/
OBJECTS_DIR = build/

OBJ = stack.o \
	utils.o \
	stack_utils.o \
	printer.o \
	printer2.o \
	sort.o \
	sort2.o \
	stack_utils2.o \
	simulation.o \
	vector.o \
	sort_b.o \
	parse.o \
	rank.o \

OBJ := $(addprefix $(OBJECTS_DIR),$(OBJ))

MAIN_OBJ = main.o
MAIN_OBJ_BONUS = checker_bonus.o

MAIN_OBJ := $(addprefix $(OBJECTS_DIR),$(MAIN_OBJ))
MAIN_OBJ_BONUS := $(addprefix $(OBJECTS_DIR),$(MAIN_OBJ_BONUS))

RM = rm -f

$(NAME) : $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME)

bonus : $(OBJ) $(MAIN_OBJ_BONUS)
	make -C lib/libft
	$(CC) $(OBJ) $(MAIN_OBJ_BONUS) -o $(NAME_BONUS) $(LIRARIES)

$(OBJECTS_DIR) :
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c | $(OBJECTS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	make -C lib/libft clean
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJ)
	$(RM) $(MAIN_OBJ_BONUS)

fclean : clean
	make -C lib/libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re
