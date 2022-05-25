#include "buildin.h"

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

void ft_pwd(t_env *e)
{	
	int	i;

	i = 3;
	save_pwd(e);
	while (e->pwd[i++])
		printf("%c", e->pwd[i]);
	printf("\n");
}
