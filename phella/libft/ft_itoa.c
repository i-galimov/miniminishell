/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <rtire@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:47 by rtire             #+#    #+#             */
/*   Updated: 2021/10/20 15:08:50 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		len = 1;
		n = n * -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*resultfunc(int n, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = (n % 10 + 48);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	return (resultfunc(n, lenlen(n)));
}
