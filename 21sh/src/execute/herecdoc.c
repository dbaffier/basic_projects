/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herecdoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:26:54 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 14:13:50 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ft_printf.h"
#include "utils.h"
#include "redirections.h"

int		ft_herecdoc(t_redirection *rd)
{
	int		fd[2];

	if (pipe(fd) == -1)
	{
		p_err("21sh: ", rd->target, " pipe error", 2);
		return (REDIR_ERROR);
	}
	write(fd[1], rd->herecdoc, ft_strlen(rd->herecdoc));
	close(fd[1]);
	make_dup2(rd->target, fd[0], STDIN_FILENO);
	close(fd[0]);
	return (REDIR_OK);
}
