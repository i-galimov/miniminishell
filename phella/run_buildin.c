#include "buildin.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	char **args = NULL;

	while (1)
	{
		line = readline("phella_shell ");
		if (line && *line)
			 ft_fork_work(argc, &line, env);
	}

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

	if (ft_strnstr(line, "echo", 4))
	{
		args[0] = line;
		ft_echo(args);
	}
	if (ft_strnstr(line, "env", 3))
		ft_env(env);
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
