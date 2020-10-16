/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:51:10 by dbaffier          #+#    #+#             */
/*   Updated: 2019/01/16 20:20:10 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	if (len)
	{
		while (len && *src)
		{
			*s++ = *src++;
			len--;
		}
		while (len)
		{
			*s++ = '\0';
			len--;
		}
	}
	return (dst);
}
