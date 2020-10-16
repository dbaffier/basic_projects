/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:14:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/09 19:07:45 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t		nb_words;

	while (*s && *s == c)
		++s;
	nb_words = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++nb_words;
		++s;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nb_words;
	char		*wrd_begin;
	char		**result;

	nb_words = ft_count_words((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd_begin = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (wrd_begin != s)
				*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
			wrd_begin = (char *)s + 1;
		}
		++s;
	}
	if (wrd_begin != s)
		*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
	*result = NULL;
	return (result - nb_words);
}
