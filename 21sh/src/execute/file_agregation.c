/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_agregation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:10:22 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:54:10 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include "redirections.h"

int		agregation_file(t_redirection *rd)
{
	mode_t	mode;
	int		fd_in;
	int		fd_out;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd_out = ft_atoi(rd->target);
	if (rd->io_number)
		fd_in = ft_atoi(rd->io_number);
	else if (rd->type & LESSER_AMPERSAND)
		fd_in = STDIN_FILENO;
	else
		fd_in = STDOUT_FILENO;
	if (ft_strdigits(rd->target))
		return (make_dup2(rd->target, fd_out, fd_in));
	else if (ft_strequ(rd->target, "-"))
	{
		close(fd_in);
		return (REDIR_OK);
	}
	else
	{
		p_err("21sh: ambigous redirection: ", rd->target, "", 2);
		return (REDIR_ERROR);
	}
}
