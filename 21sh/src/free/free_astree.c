/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_astree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:04:03 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:04:06 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "utils.h"

static void		destroy_lst_rd(t_redirection *lst)
{
	if (lst)
	{
		if (lst->io_number)
			free(lst->io_number);
		free(lst->target);
		destroy_lst_rd(lst->next);
		free(lst);
		lst = NULL;
	}
}

static void		destroy_lst_cmd(t_cmd *lst)
{
	if (lst)
	{
		free(lst->cmd);
		lst->cmd = NULL;
		destroy_lst_cmd(lst->next);
		free(lst);
		lst = NULL;
	}
}

static void		destroy_tree(t_astree *tree)
{
	if (tree)
	{
		destroy_tree(tree->right);
		if (tree->left)
			free(tree->left);
		free(tree);
	}
}

void			free_shell(t_shell *sh)
{
	if (sh->argc != 0)
	{
		ft_freetab(&(sh->argv));
		free(sh->initial);
		sh->initial = NULL;
	}
	if (sh->cmd)
		destroy_lst_cmd(sh->cmd);
	if (sh->rd)
		destroy_lst_rd(sh->rd);
	sh->argc = 0;
}

void			destroy_syntax_tree(t_lstastree *lst)
{
	if (lst)
	{
		if (lst->tree)
			destroy_tree(lst->tree);
		destroy_syntax_tree(lst->next);
		free(lst);
	}
}
