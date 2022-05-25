#include "buildin.h"

void check_buildin(char *line, t_env *e)
{
	if (!ft_strncmp(line, "pwd", ft_strlen("pwd")))
		ft_pwd(e);
	if (!ft_strncmp(line, "env", ft_strlen("env")))
		ft_env(e);
	// if (!ft_strncmp(line, "cd", ft_strlen("cd")))
	// 	ft_cd();
	// if (!ft_strncmp(line, "exit", ft_strlen("exit")))
	// 	ft_exit();
	// if (!ft_strncmp(line, "export", ft_strlen("export")))
	// 	ft_export();
	// if (!ft_strncmp(line, "unset", ft_strlen("unset")))
	// 	ft_unset();
}
