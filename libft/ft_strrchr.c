/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 09:17:07 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/07 16:28:47 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	char	ch;
	int		len;

	len = ft_strlen(s);
	t = (char *)s + len;
	ch = c;
	while (t >= s)
	{
		if (*t == ch)
			return (t);
		t--;
	}
	return (NULL);
}
