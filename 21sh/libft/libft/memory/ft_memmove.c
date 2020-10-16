/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:32:10 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/13 09:36:11 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p1;
	const char	*p2;

	p1 = dst;
	p2 = src;
	if (p2 < p1 && p1 < p2 + len)
	{
		p2 += len;
		p1 += len;
		while (len--)
			*--p1 = *--p2;
	}
	else
		while (len--)
			*p1++ = *p2++;
	return (dst);
}
