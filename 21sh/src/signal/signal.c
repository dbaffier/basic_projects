/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:23:39 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 10:03:12 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "prompt.h"
#include "execute.h"

static void		ft_sigint(int signo)
{
	write(1, "\n", 1);
	(void)signo;
}

static void		ft_void_sigint(int signo)
{
	(void)signo;
}

void			get_signal(int sig)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	if (!sig)
		signal(SIGINT, ft_sigint);
	else
		signal(SIGINT, ft_void_sigint);
}
