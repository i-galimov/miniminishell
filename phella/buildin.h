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
# include "libft/libft.h"

# define BLUE "\033[0;34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

typedef struct s_envar
{
	char *key;
	char *value;
	struct s_envar *next; 

} t_envar;

typedef struct s_env
{
	char	*pwd;
	char	*home;
	char 	**env2;

} t_env;

typedef struct s_buildin
{
	char *buildin;

} t_buildin;

// pipex_for_minishell.c
// char	*ft_pwd_path(char *cmd, char **env);
char	*ft_path(char *cmd, char **env);
void	ft_get_cmd(char *argv, char **env);
void	ft_parent_process(char **argv, char **env, int *fd);
void	ft_child_process(char **argv, char **env, int *fd);
int		ft_fork_work(int argc, char *argv[], char **env);
// save_env.c
void	save_env(char **env, t_env *e);
int		size_env(char **env);
void	save_pwd(t_env *e);
void	save_home(t_env *e);
// env
void	ft_env(t_env *e);
// echo
int		check_echo(char *line);
int		check_echo_n(char *line);
void	ft_echo(char *line);
// check_env.c
int		check_buildin(char *line, t_env *e);
// ft_pwd.c
void	ft_pwd(t_env *e);
// ft_cd.c
int		check_cd(char *line);
int		check_cd_dd(char *line);
int		check_cd_way(char *line);
void	ft_cd(char *line, t_env *e);

#endif