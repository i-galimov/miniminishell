#include "buildin.h"

int	check_cd(char *line)
{
	if (line[0] == 'c')
		if (line[1] == 'd')
			if (!line[2])
				return (1);
	if (line[0] == 'c')
		if (line[1] == 'd')
			if (line[2] == ' ')
				if (line[3] == '~')
					if (!line[4])
						return (1);
	return (0);
}

int	check_cd_dd(char *line)
{
	if (line[0] == 'c')
		if (line[1] == 'd')
			if (line[2] == ' ')
				if (line[3] == '.')
					if (line[4] == '.')
						if (!line[5])
							return (1);
	return (0);
}

int	check_cd_way(char *line)
{
	if (line[0] == 'c')
		if (line[1] == 'd')
			if (line[2] == ' ')
				if (line[3] == '/')
					if (line[4])
						return (1);
	return (0);
}

void ft_cd(char *line, t_env *e)
{	
	int	i;
	int	j;
	char *way_home;
	
	// while (e->home[j++])
	// {
	// 	i = 0;
	// 	j = 4;
	// 	way_home[i++] = e->home[j];
	// }
	if (check_cd(line))
		chdir(way_home);


	// if (check_cd_dd(line))
	// 	chdir(e->home);
	// if (check_cd_way(line))
	// 	chdir(e->home);
}