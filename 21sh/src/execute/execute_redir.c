/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:05:17 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 13:27:51 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <fcntl.h>
#include "redirections.h"

static int		make_redir(t_redirection *rd)
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

int				init_redir(t_redirection *rd)
{
	t_redirection	*save;

	save = rd;
	while (rd)
	{
		if (make_redir(rd) == REDIR_ERROR)
			return (REDIR_ERROR);
		rd = rd->next;
	}
	rd = save;
	return (REDIR_OK);
}
