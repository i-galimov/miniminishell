#ifndef BUILDIN_H
# define BUILDIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "/Users/phella/Desktop/1/minishell/libft/libft.h"

typedef struct s_envar
{
	char *key;
	char *value;
	struct s_envar *next; 

} t_envar;

typedef struct s_buildin
{
	char *buildin;

} t_buildin;

// pipex_for_minishell.c
char	*ft_path(char *cmd, char **env);
char	*ft_pwd_path(char *cmd, char **env);
void	ft_get_cmd(char *argv, char **env);
void	ft_parent_process(char **argv, char **env, int *fd);
void	ft_child_process(char **argv, char **env, int *fd);
int		ft_fork_work(int argc, char *argv[], char **env);
// env
void	ft_env(char **env);
// echo
int		ft_echo(char **arg);
int		check_new_line(char *str);



#endif