/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rd_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 01:10:39 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:45:22 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include "lexer.h"
#include "ft_printf.h"
#include "execute.h"
#include "redirections.h"

int			exec_rd_pipe(t_redirection *rd)
{
	t_redirection	*save;

	save = rd;
	while (rd)
	{
		if (exec_redir_pipe(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
		rd = rd->next;
	}
	rd = save;
	return (REDIR_OK);
}

int			exec_redir_pipe(t_redirection *rd)
{
	if (rd->type & GREATER_AMPERSAND || rd->type & LESSER_AMPERSAND)
	{
		if (agregation_file(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	else if (rd->type & DLESSER)
	{
		if (ft_herecdoc(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	else
	{
		if (ft_redirect(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	return (REDIR_OK);
}

int			handle_redir_pipe(t_redirection *rd)
{
	if (rd->type & DLESSER)
	{
		if (ft_herecdoc(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	else
	{
		if (get_fd(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	return (REDIR_OK);
}

int			init_redir_pipe(t_redirection *rd)
{
	t_redirection	*save;

	save = rd;
	while (rd)
	{
		if (handle_redir_pipe(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
		rd = rd->next;
	}
	rd = save;
	return (REDIR_OK);
}

int			init_rd_pipe(t_astree *tree)
{
	t_redirection	*rd;

	rd = ((t_astree *)tree->left)->right;
	if (init_redir_pipe(rd) == REDIR_ERROR)
		return (REDIR_ERROR);
	tree = tree->right;
	while (tree && tree->type & NODE_PIPE)
	{
		rd = ((t_astree *)tree->left)->right;
		if (init_redir_pipe(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
		tree = tree->right;
	}
	rd = ((t_astree *)tree->left)->right;
	if (init_redir_pipe(rd) == REDIR_ERROR)
		return (REDIR_ERROR);
	return (REDIR_OK);
}
