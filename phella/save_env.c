#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;
	
	i = -1;
	while (env[++i])
		e->env2[i] = ft_strdup(env[i]);
	e->env2[i] = NULL;
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
