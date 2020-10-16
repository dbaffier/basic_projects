/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:12:37 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:47:46 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include "redirections.h"

int		make_dup2(char *dst, int target, int from)
{
	if ((dup2(target, from)) != -1)
		return (REDIR_OK);
	p_err("21sh: ", dst, ": Bad file descriptor", 2);
	return (REDIR_ERROR);
}

void	save_fd(int save[10])
{
	int		i;
	int		fd;

	i = -1;
	while (++i < 10)
	{
		fd = save[i];
		if (fd != -1)
			make_dup2("Save fd", fd, i);
	}
}

void	close_save_fd(int save[10])
{
	int		i;
	int		fd;

	i = -1;
	while (++i < 10)
	{
		fd = save[i];
		if (fd != -1)
			close(fd);
	}
}

void	restore_std_fd(t_redirection *redir, int save[10])
{
	save_fd(save);
	close_save_fd(save);
	if (redir == NULL)
		return ;
	while (redir)
	{
		if (redir->fd > 0)
			close(redir->fd);
		redir = redir->next;
	}
}

void	close_pipe_rd(t_redirection *redir)
{
	if (redir == NULL)
		return ;
	while (redir)
	{
		if (redir->fd > 0)
			close(redir->fd);
		redir = redir->next;
	}
}
