/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:45:11 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:51:27 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <execute.h>
#include "ft_printf.h"
#include "utils.h"
#include "redirections.h"

int		ft_open_err(int fd, char *file)
{
	struct stat		err;

	if (fd != -1)
		return (REDIR_OK);
	else
	{
		if (stat(file, &err) == 0)
		{
			if (S_ISDIR(err.st_mode))
				p_err("21sh: ", file, " :is a directory", 2);
		}
		else if (access(file, F_OK) == -1)
			p_err("21sh: ", file, " :no such file", 2);
		else if (access(file, R_OK) == -1)
			p_err("21sh: ", file, " :permission denied", 2);
		else
			p_err("21sh: ", file, " :open error", 2);
		return (REDIR_ERROR);
	}
}

int		get_fd(t_redirection *redir)
{
	mode_t			mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (ft_strequ(redir->target, "-"))
		return (REDIR_OK);
	if (redir->type & DGREATER)
	{
		if ((redir->fd = open(redir->target, O_WRONLY | O_APPEND | O_CREAT,
						mode)) == -1)
			return (ft_open_err(redir->fd, redir->target));
	}
	else if (redir->type & LESSER)
	{
		if ((redir->fd = open(redir->target, O_RDONLY)) == -1)
			return (ft_open_err(redir->fd, redir->target));
	}
	else
	{
		if ((redir->fd = open(redir->target, O_WRONLY | O_CREAT | O_TRUNC,
						mode)) == -1)
			return (ft_open_err(redir->fd, redir->target));
	}
	return (REDIR_OK);
}
