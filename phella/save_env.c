#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;

	i = -1;
	while (env[++i])
		e->env2[i] = ft_strdup(env[i]);
	e->env2[i] = NULL;
	save_pwd(e);
	save_home(e);
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void save_pwd(t_env *e)
{
	int	i;

	i = -1;
	while (e->env2[++i])
	{
		if (e->env2[i][0] == 'P')
			if (e->env2[i][1] == 'W')
				if (e->env2[i][2] == 'D')
					if (e->env2[i][3] == '=')
					{
						e->pwd = ft_strdup(e->env2[i]);
						break ;
					}
	}
}

void save_home(t_env *e)
{
	int	i;

	i = -1;
	while (e->env2[++i])
	{
		if (e->env2[i][0] == 'H')
			if (e->env2[i][1] == 'O')
				if (e->env2[i][2] == 'M')
					if (e->env2[i][3] == 'E')
						if (e->env2[i][3] == '=')
					{
						e->home = ft_strdup(e->env2[i]);
						break ;
					}
	}
}
