#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;
	char	**temp;

	i = -1;
	while (env[++i])
	{
		e->env2[i] = ft_strdup(env[i]);
		temp = ft_split(env[i], '=');
		e->key_env[i] = temp[0];
		e->value_env[i] = temp[1];
		e->count_var = i;
	}
	e->env2[i] = NULL;
	e->key_env[i] = NULL;
	e->value_env[i] = NULL;
	save_pwd(e);
	save_home(e);
	// printf("%d\n", e->count_var);
	// int	j;
	// j = -1;
	// while (++j < i)
	// {
	// 	printf("%s\n", e->key_env[j]);
	// 	printf("%s\n", e->value_env[j]);
	// }
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
	int		i;
	char	dir[500];

	i = -1;
	// while (e->env2[++i])
	// {
	// 	if (e->env2[i][0] == 'P')
	// 		if (e->env2[i][1] == 'W')
	// 			if (e->env2[i][2] == 'D')
	// 				if (e->env2[i][3] == '=')
	// 				{
	// 					e->pwd = ft_strdup(e->env2[i]);
	// 					break ;
	// 				}
	// }
	getcwd(dir, 500);
	e->pwd = ft_strdup(dir);
	// printf("%s\n", e->pwd);
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
						if (e->env2[i][4] == '=')
					{
						e->home = ft_strdup(e->env2[i]);
						break ;
					}
	}
}
