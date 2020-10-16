/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 22:09:48 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/05 11:54:56 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_test(char const *s1, char const *s2, int a)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	if (a == 1 || a == 3)
		free((void *)s1);
	else if (a == 2 || a == 3)
		free((void *)s2);
	return (new_str);
}

char	*ft_pathjoin(const char *p1, const char *p2)
{
	char	*str;
	char	*tmp;

	if (!ft_strendswith(p1, "/"))
	{
		tmp = ft_strjoinch(p1, '/');
		str = ft_strjoin(tmp, p2);
		free(tmp);
		return (str);
	}
	str = ft_strjoin(p1, p2);
	return (str);
}
