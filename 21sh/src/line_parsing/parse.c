/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 04:26:41 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/13 11:11:42 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int				is_whitesp(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ';');
}

static int				ft_inc(char **str, int c)
{
	(*str)++;
	if (!*str || !**str || **str == '"' || **str == '\'')
		return (0);
	while (**str && **str != c)
		(*str) = (*str) + 1;
	return (1);
}

size_t					count_w(char *s)
{
	size_t		nb_words;

	if (!*s)
		return (0);
	nb_words = 0;
	while (*s)
	{
		while (*s && is_whitesp(*s))
			++s;
		if (*s == '\'')
			nb_words += ft_inc(&s, '\'');
		else if (*s == '"')
			nb_words += ft_inc(&s, '"');
		else if (*s && !is_whitesp(*s) && !is_quote(*s))
		{
			while (*s && !is_whitesp(*s) && !is_quote(*s))
				s++;
			++nb_words;
		}
		if (*s)
			++s;
	}
	return (nb_words);
}

static const char		*link_sub(char ***res, char **wrd_begin,
		char const *str, char c)
{
	while (++str && *str && *str != c)
		;
	if (*wrd_begin != str - 1)
	{
		*(*res) = ft_strsub(*wrd_begin, 1, (str - 1) - *wrd_begin);
		(*res) = (*res) + 1;
	}
	if (*str)
		str++;
	(*wrd_begin) = (char *)str;
	return (str);
}

char					**ft_parse(const char *s, size_t size)
{
	char		*wrd_begin;
	char		**result;

	if (!(result = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && is_whitesp(*s))
			s++;
		wrd_begin = (char *)s;
		if (*s == '"')
			s = link_sub(&result, &wrd_begin, s, '"');
		else if (*s == '\'')
			s = link_sub(&result, &wrd_begin, s, '\'');
		else
		{
			while (*s && !is_whitesp(*s) && !is_quote(*s))
				s++;
			if (wrd_begin != (char *)s)
				*(result++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
			wrd_begin = (char *)s + 1;
		}
	}
	*result = NULL;
	return (result - size);
}
