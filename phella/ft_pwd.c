#include "buildin.h"

void ft_pwd(t_env *e)
{	
	int	i;

	i = 3;
	while (e->pwd[i++])
		printf("%c", e->pwd[i]);
	printf("\n");
}
