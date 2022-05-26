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


void	ft_cd(char *line, t_env *e)
{	
	char	*way_home;

	way_home = ft_substr(e->home, 5, ft_strlen(e->home));
	if (check_cd(line))
		chdir(way_home);
	else
		chdir(line + 3);
	save_pwd(e);
}
