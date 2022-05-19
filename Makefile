NAME		=	minishell
#
SOURSE		=	utils.c\
				ft_split.c\
				ft_substr.c\
				list_utils.c\
				parcer.c
# 
CFLAGS		= -Wall -Werror -Wextra -I $(HEADER) -g
HEADER		= minishell.h

OBJ = $(SOURSE:%.c=%.o)
CC = gcc
#
.PHONY : all clean fclean re bonus
#
all: $(NAME)
	@say Hello peer. I am phella. Welcome to my project minishell! &
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
#
fclean : clean
	@rm -f $(NAME)
re     :	fclean all