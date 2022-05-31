#include "buildin.h"

int		check_unset_var(char *line)
{
	if (line[0] == 'u')
		if (line[1] == 'n')
			if (line[2] == 's')
				if (line[3] == 'e')
					if (line[4] == 't')
						if (line[5] == ' ')
							if (ft_isalpha(line[6]) || line[6] == '_')
								return (1);
	return (0);
}

void	ft_unset(t_env *e, char *line)
{
	int		i;

	i = 0;
	if (e->env2 == NULL)
		exit (1);
	if (!check_unset_var(line))
		return ;
	while (e->key_env[i] && ft_strcmp(e->key_env[i], line + 6) != 0)
		i++;
	if (e->env2[i] == NULL)
		return ;
	printf("%s\n", e->env2[i]);
	e->env2[i] = "\0";
}
