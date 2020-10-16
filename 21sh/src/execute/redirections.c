/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:15:36 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:54:59 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

int		ft_redirect(t_redirection *rd)
{
	if (rd->io_number)
		return (make_dup2(rd->target, rd->fd, ft_atoi(rd->io_number)));
	else if (rd->type & LESSER)
		return (make_dup2(rd->target, rd->fd, STDIN_FILENO));
	else
		return (make_dup2(rd->target, rd->fd, STDOUT_FILENO));
}
