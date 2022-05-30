/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:21:23 by rtire             #+#    #+#             */
/*   Updated: 2022/05/29 16:33:09 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*n)
		return ((char *)(h + i));
	while (i < len && h[i])
	{
		j = 0;
		if (h[i] == n[j])
		{
			while (h[i + j] == n[j] && (i + j < len) && n[j])
				j++;
			if (!n[j])
				return ((char *)(h + i));
		}
		i++;
	}
	return (NULL);
}
