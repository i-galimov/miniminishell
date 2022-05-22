#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef struct s_lst
{
	int				fd_in;
	int				fd_out;
	char			**execve;
	char			*str;
	int				pipe_flag;
	int				flag_meta;
	struct s_lst	*next;
}	t_lst;

typedef struct s_history
{
	char				*data;
	struct s_history	*next;
}	t_log;

typedef struct s_o
{
	char	**env;
	char	*input;
	char	**split;
	char	*history_log;
	char	**final_args;
	int		fd_in;
	int		count;
	int		fd_out;
	int		pipe[2];
	int		ex_code;
	int		count_env;
	int		count_final;
	int		buildin_flag;
	int		build_pipe[2];
	t_lst	*args;
	t_log	*page;
	t_lst	*final;
	t_log	*first;
}	t_o;

#endif