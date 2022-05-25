#include "buildin.h"

void	ft_env(t_env *e)
{
	int i = 0;
	while(e->env2[i])
	{
		printf ("%s\n", e->env2[i]);
		i++;
	}
}
