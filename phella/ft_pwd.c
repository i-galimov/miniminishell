#include "buildin.h"

void *save_pwd(t_env *e)
{
	int	i;

	i = -1;
	while (e->env_save[++i])
	{
		if (e->env_save[i][0] == 'P')
			if (e->env_save[i][1] == 'W')
				if (e->env_save[i][2] == 'D')
					if (e->env_save[i][3] == '=')
					{
						e->pwd = ft_strdup(e->env_save[i]);
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
