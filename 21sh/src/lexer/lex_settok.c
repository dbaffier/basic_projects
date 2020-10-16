/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_settok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:00:38 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:35:57 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			is_ionumber(char *str, char *next)
{
	if (!str || ft_strlen(str) > 1)
		return (0);
	if (ft_isdigit(*str) && (!ft_strcmp(next, ">&") || !ft_strcmp(next, "<&")
				|| !ft_strcmp(next, ">") || !ft_strcmp(next, "<")
				|| !ft_strcmp(next, ">>") || !ft_strcmp(next, "<<")))
	{
		return (1);
	}
	return (0);
}

void				fill_tok(t_tok **token, char *data, int f)
{
	if (f == 1)
	{
		if (is_ionumber((*token)->data, data))
			(*token)->operator = IO_NUMBER;
		if (!((*token)->next = malloc(sizeof(t_tok))))
			exit(2);
		*token = (*token)->next;
		tok_init(*token, ft_strlen(data) + 1);
		ft_strncpy((*token)->data, data, ft_strlen(data) + 1);
		(*token)->operator = OPERATOR;
		(*token)->type = identify_operator(data);
	}
	else
	{
		tok_init(*token, ft_strlen(data) + 1);
		ft_strncpy((*token)->data, data, ft_strlen(data) + 1);
		(*token)->operator = OPERATOR;
		(*token)->type = identify_operator(data);
	}
}

void				alone_tok(t_tok **token, char data, int *pos)
{
	if (*pos > 0)
		(*token)->data = ft_strjoinchfree((*token)->data, data);
	if (*pos == 0 && data)
	{
		tok_init(*token, 2);
		(*token)->data[0] = data;
		(*token)->data[1] = '\0';
		(*token)->operator = WORD;
		(*token)->type = 0;
	}
	*pos += 1;
}

static char			g_quote(char c)
{
	char	found;

	found = 0;
	if (c == '\'')
		found = '\'';
	else if (c == '\"')
		found = '\"';
	return (found);
}

void				h_wordtok(t_tok **token, char **input, int *pos)
{
	int		quote;

	quote = 0;
	if (*input && (**input == '"' || **input == '\''))
		quote = g_quote(**input);
	if (quote)
	{
		alone_tok(token, **input, pos);
		(*input)++;
		while (**input != quote)
		{
			alone_tok(token, **input, pos);
			(*input)++;
		}
		alone_tok(token, **input, pos);
		(*input)++;
	}
	else if (*input && **input)
	{
		if (*input && **input && **input != ' ')
			alone_tok(token, **input, pos);
		(*input)++;
	}
}
