#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!env)
		return ; 
	while (env[++i])
	{
		while (env[i][++j])
			e->env_save[i][j] = env[i][j];
	}
}
