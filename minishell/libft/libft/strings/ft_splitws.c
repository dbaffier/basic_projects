/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:28:23 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/28 09:03:52 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_words(char *s)
{
	size_t		nb_words;

	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		++s;
	nb_words = 1;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
		{
			while (*s && (*s != '\t' && *s != '\n' && *s != ' '))
				s++;
			++nb_words;
		}
		++s;
	}
	return (nb_words);
}

char			**ft_splitws(char const *s)
{
	size_t		nb_words;
	char		*wrd_begin;
	char		**result;

	nb_words = ft_count_words((char *)s);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd_begin = (char *)s;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
		{
			if (wrd_begin != s)
				*(result++) = ft_strsub(wrd_begin, 0, (s) - wrd_begin);
			wrd_begin = (char *)s + 1;
		}
		++s;
	}
	if (wrd_begin != s)
		*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
	*result = NULL;
	return (result - nb_words);
}
