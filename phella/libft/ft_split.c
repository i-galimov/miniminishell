/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <rtire@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:37:11 by rtire             #+#    #+#             */
/*   Updated: 2021/10/19 21:01:41 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	we_count_str(char const *s, char c)
{
	int	i;
	int	nmstr;

	i = 0;
	nmstr = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nmstr++;
		i++;
	}
	return (nmstr);
}

static void	*we_free_mem(char **arr, int nmstr)
{
	int	i;

	i = 0;
	while (i < nmstr)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	we_find_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**we_fill_str(char const *s, char c, int nmstr, char **arr)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (i < nmstr)
	{
		while (*s == c)
			s++;
		len = we_find_len(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (we_free_mem(arr, nmstr));
		j = 0;
		while (j < len)
		{
			arr[i][j] = *s;
			j++;
			s++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nmstr;

	if (!s)
		return (0);
	nmstr = we_count_str(s, c);
	arr = (char **)malloc(sizeof(char *) * (nmstr + 1));
	if (!arr)
		return (0);
	arr = we_fill_str(s, c, nmstr, arr);
	return (arr);
}
