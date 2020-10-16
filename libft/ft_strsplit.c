/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:14:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/09 11:48:45 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcw(char const *s, char delim)
{
	int		count;
	int		state;

	count = 0;
	state = 0;
	while (*s)
	{
		if (*s == delim)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_strciw(const char *s, char delim)
{
	size_t		len;

	len = 0;
	while (*s != delim && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			index;
	int			nb_w;

	if (!s)
		return (NULL);
	nb_w = ft_strcw(s, c);
	index = 0;
	if (!(str = (char **)malloc(sizeof(char *) * nb_w + 1)))
		return (NULL);
	while (nb_w--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(str[index] = ft_strsub(s, 0, ft_strciw(s, c))))
			return (NULL);
		s = s + ft_strciw(s, c);
		index++;
	}
	str[index] = NULL;
	return (str);
}
