/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:12:34 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 14:13:49 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		tok_init(t_tok *tok, int datasize)
{
	if (!(tok->data = malloc(datasize)))
	{
		tok = NULL;
		return ;
	}
	tok->data[0] = 0;
	tok->next = NULL;
}

void		tok_destroy(t_tok *tok)
{
	if (tok != NULL)
	{
		if (tok->data)
			free(tok->data);
		tok_destroy(tok->next);
		free(tok);
	}
}

int			identify_operator(const char *s)
{
	size_t			i;
	static t_ope	tab[] = {
		OPE_GREAT_AND, OPE_LESS_AND,
		OPE_LESS_GREAT, OPE_PIPE, OPE_SEMICOLON,
		OPE_GREATER, OPE_DGREATER, OPE_LESSER, OPE_DLESSER};

	i = 0;
	while (i < sizeof(tab) / sizeof(tab[0]))
	{
		if (!ft_strcmp(tab[i].name, s))
			return (tab[i].value);
		i++;
	}
	return (WORD);
}

char		*get_tokdup(char *str)
{
	if (*str == '<' && *(str + 1) == '<')
		return (str + 2);
	if (*str == '>' && *(str + 1) == '>')
		return (str + 2);
	if (*str == '<' && *(str + 1) == '>')
		return (str + 2);
	if ((*str == '>' || *str == '<') && *(str + 1) == '&')
		return (str + 2);
	if (*str == ' ' || *str == '<' || *str == '>' || *str == '\n'
		|| *str == ';' || *str == 0 || *str == '\t' || *str == '|')
		return (str + 1);
	return (str);
}

char		*get_token(char *start, const char *end)
{
	char	*tok;
	int		i;

	i = 0;
	if (end <= start)
		return (start);
	if (!(tok = malloc(ft_strlen(start) - ft_strlen(end) + 1)))
		return (NULL);
	while (start < end)
	{
		tok[i] = *start++;
		i++;
	}
	tok[i] = 0;
	return (tok);
}
