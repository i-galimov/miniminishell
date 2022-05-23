//#include "minishell.h"

static size_t	ft_wordlen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c && *str)
	{
		str++;
		len++;
	}
	return (len);
}

static size_t	ft_wordcount(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	if (i > 0 && str[i - 1] == c)
		count--;
	return (count);
}

static char	**ft_strfree(char **str, size_t count)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (i < count)
		{
			if (str[i] != NULL)
				free(str[i]);
			i++;
		}
		free(str);
	}
	return (NULL);
}

static char	**ft_createarr(char **res, const char *s, char c)
{
	size_t		j;
	size_t		k;

	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			continue ;
		res[j] = malloc(sizeof(char) * ft_wordlen(s, c) + 1);
		if (res[j] == NULL)
			return (ft_strfree(res, j));
		k = 0;
		while (*s != c && *s != '\0')
		{
			res[j][k] = *s;
			k++;
			s++;
		}
		res[j][k] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (res == NULL)
		return (NULL);
	ft_createarr(res, s, c);
	return (res);
}
