/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 08:54:24 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/04 11:59:00 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if ((unsigned int)s[i] == 0x00)
			return (i + 0);
		if ((unsigned int)s[i + 1] == 0x00)
			return (i + 1);
		if ((unsigned int)s[i + 2] == 0x00)
			return (i + 2);
		if ((unsigned int)s[i + 3] == 0x00)
			return (i + 3);
		i += 4;
	}
	return (i);
}
