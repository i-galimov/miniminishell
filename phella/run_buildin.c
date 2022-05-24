#include "buildin.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	// char **args = NULL;
	// t_env e;
	// save_env(env, &e);
	// ft_env(env, &e);

	while (1)
	{
		line = readline("minizhopa ");
		printf("%s\n", line);
		if (line != NULL)
			add_history(line);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
			break ;
		// if (line && *line)
		// 	ft_get_cmd(line, env);
		if (line && *line)
			system(line);
	}
	free(line);

/* 	char buildin[7][6] = 
	{
		"echo"
		"cd"
		"pwd"
		"export"
		"unset"
		"env"
		"exit"
	}; */

	// if (ft_strnstr(line, "echo", 4))
	// {
	// 	args[0] = line;
	// 	ft_echo(args);
	// }
	// if (ft_strnstr(line, "env", 3))
	// 	ft_env(env);
	// if (line == "cd")
	// 	ft_cd();
	// if (line == "pwd")
	// 	ft_pwd();
	// if (line == "export")
	// 	ft_export();
	// if (line == "unset")
	// 	ft_unset();
	// if (line == "env")
	// 	ft_env();
	// if (line == "exit")
	// 	ft_exit();
	return (0);
}
