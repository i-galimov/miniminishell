/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <rtire@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:24:27 by rtire             #+#    #+#             */
/*   Updated: 2021/10/19 16:15:45 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	findme(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (findme(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (findme(set, s1[end]) && start <= end)
		end--;
	s2 = (char *)malloc(sizeof(*s2) * (end - start + 2));
	if (!s2)
		return (0);
	ft_strlcpy(s2, &s1[start], (end - start + 2));
	return (s2);
}
