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
	int	flag;

	i = -1;
	flag = 0;
	if (check_export(line))
	{
		sort_env(e);
		while (e->sort_env2[++i])
		{
			printf("declare -X ");
			printf("%s\n", e->sort_env2[i]);
		}
	}
	i = -1;
	if (check_export_var(line))
	{
		while (line[++i])
		{
			if (line[i] == '=')
			{
				flag = 1;
				e->count_var += 1;
				e->count_sort_var += 1;
				temp_sort_env(e, line);
				temp_env(e, line);
			}
		}
		if (flag == 0)
			temp_sort_env(e, line);
		// temp_env2(e, e->env2);
		// temp_env2(line, e->sort_env2);
	}
}
