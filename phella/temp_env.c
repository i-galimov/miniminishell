#include "buildin.h"

void	temp_sort_env(t_env *e, char *line)
{
	int	i;

	i = -1;
	e->temp_sort_env2 = malloc(sizeof(char *) * e->count_sort_var + 1);
	if (!e->temp_sort_env2)
		return ;
	while (e->sort_env2[++i])
		e->temp_sort_env2[i] = ft_strdup(e->sort_env2[i]);
	e->temp_sort_env2[e->count_sort_var] = ft_strdup(line + 7);
	e->temp_sort_env2[e->count_sort_var + 1] = NULL;
	i = -1;
	e->sort_env2 = e->temp_sort_env2;
}

void	temp_env(t_env *e, char *line)
{
	int	i;

	i = -1;
	e->temp_env2 = malloc(sizeof(char *) * e->count_var + 1);
	if (!e->temp_env2)
		return ;
	while (e->env2[++i])
		e->temp_env2[i] = ft_strdup(e->env2[i]);
	e->temp_env2[e->count_var] = ft_strdup(line + 7);
	e->temp_env2[e->count_var + 1] = NULL;
	i = -1;
	e->env2 = e->temp_env2;
}