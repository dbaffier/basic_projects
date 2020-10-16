/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_white.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:31:37 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 15:31:50 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "prompt.h"

int		ft_wordlen_ws(char *str)
{
	int i;

	i = 0;
	while ((WHITESPACE(str[i])) && (str[i] != '\0'))
		str++;
	while (!(WHITESPACE(str[i])) && (str[i] != '\0'))
		i++;
	return (i);
}

int		ft_countwords_ws(char *str)
{
	int	word_count;
	int i;
	int not_white;

	i = 0;
	word_count = 0;
	not_white = 0;
	while (str[i] != '\0')
	{
		while ((WHITESPACE(str[i])) && (str[i] != '\0'))
			i++;
		while (!(WHITESPACE(str[i])) && (str[i] != '\0'))
		{
			i++;
			not_white++;
		}
		while ((WHITESPACE(str[i])) && (str[i] != '\0'))
			i++;
		word_count++;
	}
	if (!not_white)
		word_count = 0;
	return (word_count);
}

char	**ft_split_whitespaces(char *str, int i)
{
	int		word_count;
	int		words_entered;
	char	**words;
	char	*word;

	words_entered = 0;
	word_count = ft_countwords_ws(str);
	if (!(words = (char**)malloc(sizeof(char*) * (word_count + 1))))
		return (NULL);
	while (words_entered < word_count)
	{
		i = 0;
		word = (char*)malloc(sizeof(char) * (ft_wordlen_ws(str) + 1));
		while ((WHITESPACE(str[0])) && (str[0] != '\0'))
			str++;
		while (!(WHITESPACE(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
	}
	words[word_count] = 0;
	(!word_count) ? free(words) : word_count;
	if (!word_count)
		return (NULL);
	return (words);
}

char	**alloc_here_tab(char *here_tab_z)
{
	char	**here_tab;

	here_tab = NULL;
	if (!(here_tab = ft_memalloc(sizeof(char **) * (4096))))
		return (0);
	here_tab[0] = ft_strdup(here_tab_z);
	here_tab[1] = NULL;
	free(here_tab_z);
	return (here_tab);
}
