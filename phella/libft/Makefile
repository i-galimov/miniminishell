# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtire <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 11:15:49 by rtire             #+#    #+#              #
#   Updated: 2022/01/18 15:17:18 by rtire            ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

LIST = 	ft_isalpha.c		ft_isdigit.c	ft_isalnum.c\
		ft_isascii.c		ft_isprint.c	ft_strlen.c\
		ft_memset.c			ft_bzero.c		ft_memcpy.c\
		ft_memmove.c		ft_strlcpy.c	ft_strlcat.c\
		ft_toupper.c		ft_tolower.c	ft_strchr.c\
		ft_strrchr.c		ft_strncmp.c    ft_memchr.c\
		ft_memcmp.c			ft_strnstr.c	ft_atoi.c\
		ft_calloc.c			ft_strdup.c		ft_substr.c\
		ft_strjoin.c		ft_strtrim.c	ft_split.c\
		ft_itoa.c			ft_strmapi.c	ft_striteri.c\
		ft_putchar_fd.c		ft_putstr_fd.c	ft_putendl_fd.c\
		ft_putnbr_fd.c		ft_lstnew.c		ft_lstiter.c\
		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c\
		ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c\

HEADER = libft.h

OBJ = $(LIST:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

GREEN='\033[0;32m'
RED='\033[0;31m'
GRAY='\033[2;37m'

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@ar rcs $(NAME) $?
	@echo $(GREEN)"➤ - Compiling $(NAME)..."

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $(GREEN)"█"

clean :
	@rm -f $(OBJ)

fclean : clean
	@$(RM) $(NAME)
	@echo $(RED)"- REMOVED $(NAME) -"

re : fclean all




