/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:48:56 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/05 12:14:35 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*copy;
	size_t		len;

	len = ft_strlen(s1) + 1;
	if (!(copy = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strncpy(copy, s1, len);
	return (copy);
}
