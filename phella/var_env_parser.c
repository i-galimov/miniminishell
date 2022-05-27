#include "buildin.h"

int		check_var_env(char *line)
{
	if (line[0] == '$')
		if (ft_isalpha(line[1]) || line[1] == '_')
			return (1);
	return (0);
}

char	*var_env_parser(t_env *e, char *line)
{
	int		i;
	char	**var_env;

	i = 0;
	if (e->env2 == NULL)
		exit (1);
	if (!check_var_env(line))
		return (NULL);
	while (e->env2[i] && ft_strnstr(e->env2[i], line + 1, ft_strlen(line)) == 0)
		i++;
	if (e->env2[i] == NULL)
		return (NULL);
	var_env = ft_split(ft_strnstr(e->env2[i], line + 1, ft_strlen(line)), '=');
	printf("%s\n", var_env[1]);
	return (var_env[1]);
}
