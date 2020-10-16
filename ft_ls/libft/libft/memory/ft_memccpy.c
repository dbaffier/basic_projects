/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 09:46:37 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/07 13:32:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char				*d;
	const unsigned char			*s;
	unsigned char				u;

	u = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n)
	{
		while (n--)
		{
			*d = *s;
			if (*d++ == u)
				return (d);
			s++;
		}
	}
	return (NULL);
}
