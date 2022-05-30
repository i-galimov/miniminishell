#include "buildin.h"

void	ft_env(t_env *e)
{
	int i = 0;
	while(e->env2[i])
	{
		if (e->env2[i][0] != '\0')
			printf ("%s\n", e->env2[i]);
		i++;
	}
}
