#include "buildin.h"

int		check_exit(char *line)
{
	if (line[0] == 'e')
		if (line[1] == 'x')
			if (line[2] == 'i')
				if (line[3] == 't')
				{
					if (!line[4])
						exit(0);
					if (line[4] == ' ')
						return (check_exit_d(line));
				}
	return (0);
}

int		check_exit_d(char *line)
{
	int	i;

	i = 5;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else if (!ft_isdigit(line[i]))
		{
			printf("exit: ");
			printf("%s", line + 5);
			printf(": numeric argument required\n");
			return (0);
		}
	}
	return (1);
}

void	ft_exit(char *line)
{	
	int	exit_code;

	if (check_exit(line))
	{
		exit_code = ft_atoi(line + 5);
		while (exit_code >= 256)
			exit_code %= 256;
		exit(exit_code);
	}
}
