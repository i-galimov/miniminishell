#include "buildin.h"

int		check_export(char *line)
{
	if (line[0] == 'e')
		if (line[1] == 'x')
			if (line[2] == 'p')
				if (line[3] == 'o')
					if (line[4] == 'r')
						if (line[5] == 't')
							if (!line[6])
								return (1);
	return (0);
}
int		check_export_var(char *line)
{
	if (line[0] == 'e')
		if (line[1] == 'x')
			if (line[2] == 'p')
				if (line[3] == 'o')
					if (line[4] == 'r')
						if (line[5] == 't')
							if (line[6] == ' ')
							{
								if (ft_isalpha(line[7]) || line[7] == '_')
									return (1);
								else
								{
									printf("export: ");
									printf("%s", line + 7);
									printf(": not a valid identifier\n");
								}
							}
	return (0);
}

void	sort_env(t_env *e)
{
	int		i;
	int		j;
	int		flag;
	char	*temp;

	flag = 1;
	while (flag == 1)
	{
		i = -1;
		flag = 0;
		while (++i < e->count_var - 1)
		{
			if (e->sort_env2[i][0] == e->sort_env2[i + 1][0])
			{
				j = 1;
				while (e->sort_env2[i][j] == e->sort_env2[i + 1][j])
					j++;
				if (e->sort_env2[i][j] && e->sort_env2[i + 1][j] && e->sort_env2[i][j] > e->sort_env2[i + 1][j])
				{
					temp = e->sort_env2[i];
					e->sort_env2[i] = e->sort_env2[i + 1];
					e->sort_env2[i + 1] = temp;
					flag = 1;
				}
			}
			else if (e->sort_env2[i][0] > e->sort_env2[i + 1][0])
			{
				temp = e->sort_env2[i];
				e->sort_env2[i] = e->sort_env2[i + 1];
				e->sort_env2[i + 1] = temp;
				flag = 1;
			}
		}
	}
}

void	ft_export(char *line, t_env *e)
{
	int	i;

	i = -1;
	if (check_export(line))
	{
		sort_env(e);
		while (e->sort_env2[++i])
		{
			printf("declare -X ");
			printf("%s\n", e->sort_env2[i]);
		}
	}
	if (check_export_var(line))
	{
		e->count_var += 1;
		temp_env(e, line);
		temp_sort_env(e, line);
		// temp_env2(e, e->env2);
		// temp_env2(line, e->sort_env2);
	}
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
	while (e->env2[++i])
		free(e->env2[i]);
	free(e->env2);
	e->env2 = e->temp_env2;
}

void	temp_sort_env(t_env *e, char *line)
{
	int	i;

	i = -1;
	while (e->sort_env2[++i])
		e->temp_env2[i] = ft_strdup(e->sort_env2[i]);
	e->temp_env2[e->count_var] = ft_strdup(line + 7);
	e->temp_env2[e->count_var + 1] = NULL;
	i = -1;
	while (e->sort_env2[++i])
		free(e->sort_env2[i]);
	free(e->sort_env2);
	e->sort_env2 = e->temp_env2;
}

// void	temp_env2(char *line, char **array)
// {
// 	char	**new_array;
// 	int		i;
// 	int		count_array;

// 	i = -1;
// 	count_array = 0;
// 	while (array[count_array])
// 		count_array++;
// 	count_array += 2 ;
// 	new_array = malloc(sizeof(char *) * count_array);
// 	if (!new_array)
// 		return ;
// 	while (array[++i])
// 		new_array[i] = ft_strdup(array[i]);
// 	new_array[count_array - 1] = ft_strdup(line + 7);
// 	new_array[count_array] = NULL;
// 	i = -1;
// 	while (array[++i])
// 		free(array[i]);
// 	free(array);
// 	array = new_array;
// }
