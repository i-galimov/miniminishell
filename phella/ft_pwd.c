#include "buildin.h"

void ft_pwd(t_env *e)
{
	char	dir[500];

	getcwd(dir, 500);
	printf("%s\n", dir);
}
