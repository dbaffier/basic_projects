/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:10:28 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/07 16:29:06 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(int n)
{
	size_t	count;

	count = 0;
	while (n /= 10)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char				*str;
	size_t				size;
	unsigned int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	size = count(n);
	if (n < 0)
	{
		n = -n;
		++size;
		sign = -1;
	}
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	str[size--] = n % 10 + '0';
	while (n /= 10)
		str[size--] = n % 10 + '0';
	if (sign)
		str[size] = '-';
	return (str);
}
