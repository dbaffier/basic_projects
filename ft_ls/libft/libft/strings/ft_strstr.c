/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 09:01:14 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/05 16:05:24 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	i = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_memcmp(haystack, needle, i))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
