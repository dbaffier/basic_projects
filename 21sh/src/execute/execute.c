/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:26:25 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:12:11 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

static int		execute(t_astree *tree, t_shglobal *shg)
{
	if (tree == NULL)
		return (0);
	if (tree->type & NODE_PIPE)
		return (execute_pipe(tree, shg));
	else if (tree->type & NODE_CMDPATH)
		return (execute_simple(tree->left, shg));
	return (1);
}

void			execute_syntax_tree(t_lstastree *lst, t_shglobal *shg,
		struct termios *save, char **line)
{
	if (lst == NULL)
		return ;
	(void)save;
	shg->line = line;
	while (lst)
	{
		shg->exit_status = execute(lst->tree, shg);
		lst = lst->next;
	}
}
