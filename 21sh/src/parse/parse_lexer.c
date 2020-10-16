/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:49:07 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/18 12:47:39 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"

static t_astree	*set_cmd(t_tok **lst)
{
	t_astree		*node;
	t_cmd			*cmd;
	t_redirection	*redir;

	node = create_leaf();
	redir = NULL;
	cmd = NULL;
	while (*lst)
	{
		if ((*lst)->type & PIPE || (*lst)->type & SEMICOLON)
			break ;
		if ((*lst)->operator == IO_NUMBER)
			exaust_ionumber(lst, &redir);
		else if ((*lst)->operator == OPERATOR)
			exaust_operator(lst, &redir);
		else
			exaust_cmd(lst, &cmd);
	}
	node->left = cmd;
	node->right = redir;
	return (node);
}

static t_astree	*identify_cmd(t_tok **lst)
{
	t_astree	*tree;
	t_tok		*tmp;

	tmp = NULL;
	if (!lst || !*lst)
		return (NULL);
	tree = create_leaf();
	tree->left = set_cmd(lst);
	if (*lst && (*lst)->type & PIPE)
	{
		free((*lst)->data);
		tree->type |= NODE_PIPE;
		tmp = (*lst)->next;
		if ((*lst)->next)
			tree->right = identify_cmd(&tmp);
		*lst = tmp;
	}
	else
		tree->type |= NODE_CMDPATH;
	return (tree);
}

t_lstastree		*parse_lexer(t_tok **lst)
{
	t_lstastree		*tok_lst;
	t_tok			*tmp;

	if (!lst || !*lst)
		return (NULL);
	if (!(tok_lst = malloc(sizeof(t_lstastree))))
		return (NULL);
	tok_lst->tree = identify_cmd(lst);
	tok_lst->next = NULL;
	if (*lst && (*lst)->type & SEMICOLON)
	{
		free((*lst)->data);
		tmp = (*lst)->next;
		tok_lst->next = parse_lexer(&tmp);
	}
	return (tok_lst);
}
