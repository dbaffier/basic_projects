/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:27:46 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:36:00 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchfree(char *s1, char c)
{
	char		*str;
	size_t		i;
	size_t		s1_len;

	if (!c)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!(str = ft_strnew(s1_len + 2)))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(str + i) = *(s1 + i);
	*(str + i) = c;
	*(str + i + 1) = 0;
	if (s1)
		free(s1);
	return (str);
}
