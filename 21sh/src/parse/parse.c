/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:52:47 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/18 12:54:51 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"
#include "parse.h"
#include "utils.h"

static int		parse_err(char *str)
{
	write(2, "syntax error near `", 19);
	write(2, str, ft_strlen(str));
	write(2, "' \n", 3);
	return (0);
}

static void		free_tok(t_tok *tok)
{
	if (tok)
	{
		if (tok->data)
			free(tok->data);
		free_tok(tok->next);
		free(tok);
	}
}

static int		lex_operator_ok(t_tok *lst)
{
	if (lst->type & SEMICOLON)
	{
		if (lst->next && lst->next->type & PIPE)
			return (parse_err(lst->next->data));
		else if (lst->next && lst->next->type & SEMICOLON)
			return (parse_err(lst->next->data));
	}
	else if (!(lst->type & SEMICOLON || lst->type & PIPE))
	{
		if (lst->next && (!(lst->next->type & SEMICOLON))
				&& lst->next->operator == OPERATOR)
			return (parse_err(lst->next->data));
	}
	else if (lst->type & PIPE)
	{
		if (lst->next && lst->next->operator == OPERATOR)
			return (parse_err(lst->next->data));
	}
	if ((!(lst->type & SEMICOLON)) && !lst->next)
		return (parse_err("\\n"));
	return (1);
}

static int		lex_ok(t_tok *lst)
{
	if (!lst)
		return (0);
	if (lst->type & PIPE)
		return (parse_err(lst->data));
	while (lst)
	{
		if (lst && lst->operator == OPERATOR && lex_operator_ok(lst) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int				parse(t_lex *buff, t_lstastree **syntax_tree,
		char **line, t_shglobal *shg)
{
	t_tok		*tempo;

	(void)shg;
	if (buff->ntoks == 0)
	{
		ft_freetab(&line);
		return (-1);
	}
	tempo = buff->llisttok;
	if (lex_ok(tempo) == 0)
	{
		free_tok(buff->llisttok);
		ft_freetab(&line);
		*syntax_tree = NULL;
		return (-1);
	}
	tempo = buff->llisttok;
	*syntax_tree = parse_lexer(&tempo);
	return (0);
}
