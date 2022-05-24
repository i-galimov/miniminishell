# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtire <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:31:58 by rtire             #+#    #+#              #
#    Updated: 2022/05/20 18:32:08 by rtire            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

#SOURCE		=	utils.c\
#				ft_split.c\
#				ft_substr.c\
#				list_utils.c\
#				parcer.c

SOURCE = main.c

HEADER = minishell.h

OBJ = $(SOURCE:%.c=%.o)

CFLAGS		= -Wall -Werror -Wextra #-g

CC = gcc

LIBFT = libft/libft.a

BLUE='\033[0;34m'
GRAY='\033[2;37m'
GREEN='\033[0;32m'
RED='\033[0;31m'

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@echo $(GREEN)"➤	 - Compiling $(NAME)..."
	@make -C ./libft/
	@$(CC) $(CFLAGS) -I$(HEADER) $(LIBFT) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- COMPILED -"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@
	@printf $(BLUE)"█"

clean :
	@echo $(GREEN) "     - Removing object files..."
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@echo $(GREEN)"      - Removing $(NAME)..."
	@$(RM) $(NAME)
	@echo $(RED)"- REMOVED $(NAME) -"
	@make fclean -C ./libft

re     :	fclean all
