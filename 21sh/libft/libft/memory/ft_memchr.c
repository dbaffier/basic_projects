/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:39:52 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/06 16:52:10 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n--)
		if (*t++ == (unsigned char)c)
			return ((void *)(t - 1));
	return (NULL);
}
