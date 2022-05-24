#include "buildin.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	int		pid;
	t_env	e;

	e.env_save = (char **) malloc(size_env(env) * 1500);
	// save_env(env, &e);

	// ft_env(env, &e);
	while (1)
	{
		line = readline(BLUE"minizhopa ");
		printf("%s\n", line);
		if (line != NULL)
			add_history(line);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
			break ;
		if (line && *line)
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
	}
	free(line);
	return (0);
}
