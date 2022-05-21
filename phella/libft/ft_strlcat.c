/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:47:09 by rtire             #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	a = dst_len;
	if (dst_len < dstsize)
	{
		while (src[i] && dst_len < dstsize - 1)
		{
			dst[dst_len] = src[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = '\0';
		return (ft_strlen(src) + a);
	}
	return (ft_strlen(src) + dstsize);
}
