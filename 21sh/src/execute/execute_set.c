/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:16:44 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:04:25 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"
#include "redirections.h"

int		open_redir(t_shell *sh)
{
	t_redirection	*rd;

	rd = sh->rd;
	while (rd)
	{
		if (rd->type & GREATER_AMPERSAND || rd->type & LESSER_AMPERSAND
				|| rd->type & DLESSER)
			;
		else if (get_fd(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
		rd = rd->next;
	}
	return (REDIR_OK);
}

int		set_exec(t_shell *sh)
{
	t_redirection	*rd;

	rd = sh->rd;
	if (rd)
	{
		if (init_redir(rd) != REDIR_OK)
			return (1);
	}
	return (0);
}
