#include "buildin.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	int		pid;
	t_env	e;

	e.env2 = malloc(sizeof(char *) * size_env(env) + 1);
	e.sort_env2 = malloc(sizeof(char *) * size_env(env) + 1);
	e.key_env = malloc(sizeof(char *) * size_env(env) + 1);
	e.value_env = malloc(sizeof(char *) * size_env(env) + 1);
	save_env(env, &e);
	while (1)
	{
		line = readline(GREEN"minizhopa-> "WHITE);
		// printf(RED"input(line):'%s'\n", line);
		if (line != NULL)
			add_history(line);
		if (line && *line && !check_buildin(line, &e) && !var_env_parser(&e, line))
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
