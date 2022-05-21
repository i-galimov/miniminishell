#include "buildin.h"

int main(void)
{
	char *line;
	char **args = NULL;

	line = readline("minishell$ ");	

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
