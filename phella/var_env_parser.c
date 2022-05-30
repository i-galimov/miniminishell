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
	char	*var_env;

	i = 0;
	if (e->env2 == NULL)
		exit (1);
	if (!check_var_env(line))
		return (NULL);
	while (e->key_env[i] && ft_strcmp(e->key_env[i], line + 1) != 0)
		i++;
	if (e->key_env[i] == NULL)
		return (NULL);
	var_env = e->value_env[i];
	printf("%s\n", var_env);
	return (var_env);
}

// char	*var_env_parser(t_env *e, char *line)
// {
// 	int		i;
// 	char	**var_env;

// 	i = 0;
// 	if (e->env2 == NULL)
// 		exit (1);
// 	if (!check_var_env(line))
// 		return (NULL);
// 	while (e->env2 && ft_strcmp(e->env2[i], line + 1) != 0)
// 		i++;
// 	if (e->env2[i] == NULL)
// 		return (NULL);
// 	var_env = ft_split(e->env2[i], '=');
// 	printf("%s\n", var_env[1]);
// 	return (var_env[1]);
// }
