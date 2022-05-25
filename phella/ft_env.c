#include "buildin.h"

void	ft_env(t_env *e)
{
	int i = 0;
	while(e->env_save[i])
	{
		printf ("%s\n", e->env_save[i]);
		i++;
	}
}
