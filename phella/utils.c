#include "buildin.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1 ++;
		s2 ++;
	}
	return (0);
}