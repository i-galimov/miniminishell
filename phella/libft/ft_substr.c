/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <rtire@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:37:53 by rtire             #+#    #+#             */
/*   Updated: 2021/10/18 13:35:49 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ss = malloc(len + 1);
	if (!ss)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(ss, &s[start], len + 1);
	else
		*ss = '\0';
	return (ss);
}
