#include "buildin.h"

int	check_buildin(char *line, t_env *e)
{
	if (!ft_strncmp(line, "pwd", ft_strlen("pwd")))
	{
		ft_pwd(e);
		return (1);
	}
	if (!ft_strncmp(line, "env", ft_strlen("env")))
	{
		ft_env(e);
		return (1);
	}
	if (!ft_strncmp(line, "echo", ft_strlen("echo")))
	{
		ft_echo(line);
		return (1);
	}
	if (!ft_strncmp(line, "cd", ft_strlen("cd")))
	{
		ft_cd(line, e);
		return (1);
	}
	if (!ft_strncmp(line, "exit", ft_strlen("exit")))
	{
		ft_exit(line);
		return (1);
	}
	if (!ft_strncmp(line, "export", ft_strlen("export")))
	{
		ft_export(line, e);
		return (1);
	}
	if (!ft_strncmp(line, "unset", ft_strlen("unset")))
	{
		ft_unset(e, line);
		return (1);
	}
	return (0);
}
