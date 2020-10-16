/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:57:21 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 19:31:31 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start] && len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
