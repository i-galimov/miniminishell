/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:16:18 by rtire             #+#    #+#             */
/*   Updated: 2021/10/12 16:30:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (i < len)
		{
			i++;
			*(char *)(dst + len - i) = *(char *)(src + len - i);
		}
	}
	return (dst);
}
