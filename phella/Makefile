NAME = minizhopa

SOURCE		=	ft_cd.c\
				ft_echo.c\
				ft_env.c\
				ft_exit.c\
				ft_export.c\
				ft_pwd.c\
				ft_unset.c\
				pipex_for_minishell.c\
				save_env.c\
				minizhopa.c

HEADER = buildin.h

OBJ = $(SOURCE:%.c=%.o)

READLINE_FLAGS	=	-lreadline

CFLAGS	= -I /Users/$(USER)/.brew/opt/readline/include -g #-Wall -Werror -Wextra

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
	@$(CC) $(CFLAGS) -I$(HEADER) $(LIBFT) $(OBJ) -o $(NAME) $(READLINE_FLAGS)
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