/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:43:44 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 09:47:46 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "parse.h"

int				exit_err(char *err, int status)
{
	write(2, err, ft_strlen(err));
	return (status);
}

static int		catch_sig(int status, pid_t pid, char *msg)
{
	write(2, "[", 1);
	ft_putnbr_fd(pid, 2);
	write(2, "]", 1);
	ft_putchar('\t');
	ft_putstr_fd(msg, 2);
	ft_putchar(' ');
	write(2, "\n", 1);
	return (status);
}

int				exit_status(int status, pid_t pid)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if ((WTERMSIG(status)) == 6)
			return (catch_sig(status, pid, S_ABORT));
		if ((WTERMSIG(status)) == 8)
			return (catch_sig(status, pid, S_FLOATING));
		if ((WTERMSIG(status)) == 10)
			return (catch_sig(status, pid, S_BUS_ERROR));
		if ((WTERMSIG(status)) == 11)
			return (catch_sig(status, pid, S_SEGFAULT));
		return (WTERMSIG(status));
	}
	return (EXIT_FAILURE);
}
