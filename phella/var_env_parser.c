#include "buildin.h"

// void	var_env_parser(t_env *e)
// {
// 	int		i;
// 	int		j;
// 	t_envar	v;

// 	i = 0;
// 	while (e->env2[i++])
// 	{
// 		j = 0;
// 		while (e->env2[i][j++] != '=')
// 		{

// 			v.key = ft_substr(e->env2[i], 0, j);
// 			v.value = ft_substr(e->env2[i], j, ft_strlen(e->env2[i]));
// 			// v = v.next; 
// 		}
// 	}
// 	printf("%s\n", v.key);
// 	printf("%s\n", v.value);
// }

// t_envar	*add_envar(char **var_env)
// {
// 	int		i;
// 	int		j;
// 	t_envar	*envarlist;

// 	i = 0;
// 	envarlist = NULL;
// 	while (var_env[i]) 
// 	if (var)
// }

// void	var_env_parser(t_env *e)
// {
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	k = 0;
// 	while (e->env2[i++])
// 	{
// 		j = 0;
// 		while (e->env2[i][j++] != '=')
// 		{
// 			e->envar[k] = ft_substr(e->env2[i], 0, j);
// 			e->envar[k + 1] = ft_substr(e->env2[i], j, ft_strlen(e->env2[i]));
// 			k++; 
// 		}
// 	}
// 	printf("%s\n", e->envar[0]);
// 	printf("%s\n", e->envar[1]);
// 	printf("%s\n", e->envar[2]);
// 	printf("%s\n", e->envar[3]);
// }
