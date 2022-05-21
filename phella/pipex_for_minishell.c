#include "buildin.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*piece_path;
	char	*res;

	i = 0;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (env[i] == NULL)
		return (0);
	all_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		piece_path = ft_strjoin(all_paths[i], "/");
		res = ft_strjoin(piece_path, cmd);
		if (access(res, F_OK) == 0)
			return (res);
		else
			free(res);
	}
	return (0);
}

char	*ft_pwd_path(char *cmd, char **env)
{
	int		i;
	char	*pwd_path;
	char	*res;
	int		j;

	i = 0;
	j = -1;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strnstr(env[i], "PWD=", 4) == 0)
		i++;
	if (env[i] == NULL)
		exit(0);
	pwd_path = (char *)malloc((ft_strlen(env[i]) - 4) * sizeof(char));
	while (++j < (int)ft_strlen(env[i]) - 4)
		pwd_path[j] = env[i][j + 4];
	pwd_path = ft_strjoin(pwd_path, "/");
	res = ft_strjoin(pwd_path, cmd);
	if (access(res, F_OK) == 0)
		return (res);
	else
		free(res);
	exit(0);
}

void	ft_get_cmd(char *argv, char **env)
{
	char	**cmd;
	char	**cmd2;
	char	*path;
	int		i;

	i = 0;
	cmd2 = ft_split(argv, ' ');
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
	{	
		cmd = ft_split(argv, '/');
		while (cmd[i])
			i++;
		cmd = ft_split(cmd[i - 1], ' ');
		execve(cmd2[0], cmd, env);
	}
	path = ft_path(cmd[0], env);
	if (path == NULL)
		path = ft_pwd_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{	
		perror("Command error");
		exit(1);
	}
}

void	ft_parent_process(char **argv, char **env, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		write(2, "Permission denied error\n", 24);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	ft_get_cmd(argv[3], env);
}

void	ft_child_process(char **argv, char **env, int *fd)
{
	// if (access(argv[1], F_OK) != 0)
	// {
	// 	write(2, "No such file or directory error\n", 32);
	// 	exit(1);
	// }
	// if (access(argv[1], R_OK) != 0)
	// {
	// 	write(2, "Permission denied error\n", 25);
	// 	exit(1);
	// }
	// dup2(fd[1], 1);
	// dup2(open(argv[1], O_RDONLY), 0);
	// close(fd[0]);
	ft_get_cmd(argv[0], env);
}

int	ft_fork_work(int argc, char *argv[], char **env)
{
	int		pid;
	int		fd[2];

	pid = fork();

	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
		ft_child_process(argv, env, fd);
	// ft_parent_process(argv, env, fd);
	// close(fd[0]);
	// close(fd[1]);
	return (0);
}