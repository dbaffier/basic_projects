/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:08:56 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:38:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"
#include "expansions.h"

static char		*char_end_quotes(char *s, size_t start, char del)
{
	char	*new;
	size_t	len;

	len = start;
	start++;
	while (s[start] != del)
		start++;
	start++;
	if (!(new = ft_memalloc((start - len) + 1)))
		return (NULL);
	new = ft_strncpy(new, &s[len], (start - len));
	return (new);
}

static char		*grep_expand(char *s, size_t end)
{
	char	*new;
	size_t	start;

	new = NULL;
	start = end;
	end++;
	while (s[end] && (ft_isalnum(s[end]) || s[end] == '_'))
		end++;
	if ((start + 1) == end)
		return (NULL);
	if (!(new = ft_memalloc(sizeof(char) * (end - start) + 1)))
		return (NULL);
	ft_strncpy(new, &s[start], (end - start));
	return (new);
}

static size_t	special_expand(char c)
{
	static char		tab[] = "?_$0";
	size_t			i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

static char		*expand_s_dollar(char *s, t_shglobal *shg,
		size_t *pos, char *curr)
{
	char	*expand;

	if (special_expand(s[*pos + 1]))
	{
		curr = add_string(curr, expand_special(s[*pos + 1], shg), 3);
		*pos += 2;
	}
	else if (s[*pos + 1])
	{
		expand = grep_expand(s, *pos);
		if (expand)
		{
			curr = add_expand(curr, search_expand(expand, shg), 1);
			*pos += ft_strlen(expand);
			free(expand);
		}
		else
		{
			curr = ft_strjoinchfree(curr, s[*pos]);
			*pos += 1;
		}
	}
	return (curr);
}

char			*expand_dollar(char *s, t_shglobal *shg)
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1] == 0)
			i++;
		else if (s[i] == '\\' && ((i = i + 1)))
			new = ft_strjoinchfree(new, s[i++]);
		else if (s[i] == '\'')
		{
			new = add_string(new, char_end_quotes(s, i++, '\''), 3);
			while (s[i++] != '\'')
				;
		}
		else if (s[i] == '$' && s[i + 1] != 0)
			new = expand_s_dollar(s, shg, &i, new);
		else
			new = ft_strjoinchfree(new, s[i++]);
	}
	free(s);
	return (new);
}
