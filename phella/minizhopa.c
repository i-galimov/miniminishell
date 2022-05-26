#include "buildin.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	int		pid;
	t_env	e;

	e.env2 = malloc(sizeof(char *) * size_env(env) + 1);
	e.envar = malloc((sizeof(char *) * size_env(env) + 1) * 2);
	save_env(env, &e);
	// var_env_parser(&e);
	while (1)
	{
		line = readline(GREEN"minizhopa-> "WHITE);
		// printf(RED"input(line):'%s'\n", line);
		if (line != NULL)
			add_history(line);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
			break ;
		if (line && *line && !check_buildin(line, &e))
		{	
			pid = fork();
			if (pid == 0)
			{
				ft_get_cmd(line, env);
				waitpid(pid, 0, 0);
			}
		}
		// if (line && *line)
		// 	system(line);
		free(line);
	}
	return (0);
}
