/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:54:10 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/18 12:49:22 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"
#include <stdlib.h>

t_astree		*create_leaf(void)
{
	t_astree	*new;

	if (!(new = malloc(sizeof(t_astree))))
		return (NULL);
	new->left = NULL;
	new->type = 0;
	new->right = NULL;
	return (new);
}

t_cmd			*create_cmd(char *arg, int type)
{
	t_cmd	*node;

	if (!(node = malloc(sizeof(t_cmd))))
		return (NULL);
	node->next = NULL;
	node->cmd = arg;
	node->type = type;
	return (node);
}

t_redirection	*create_redir(char *io_n, char *target, char *herec, int type)
{
	t_redirection	*redir;

	if (!(redir = ft_memalloc(sizeof(t_redirection))))
		return (NULL);
	redir->target = target;
	redir->type = type;
	redir->herecdoc = herec;
	redir->io_number = io_n == NULL ? NULL : io_n;
	redir->fd = 0;
	redir->next = NULL;
	return (redir);
}
