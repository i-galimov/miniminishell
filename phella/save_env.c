#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;
	int		j;

	printf("zhopa\n");
	i = -1;
	j = -1;
	if (env == NULL)
		return ;
	 
	while (env[++i])
	{
		while (env[i][++j])
			e->env_save[i][j] = env[i][j];
	}
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("--> %s", env[i]);
		i++;
	}
	return (i);
}

