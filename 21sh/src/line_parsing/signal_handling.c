/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:58:06 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/27 13:39:20 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		signal_infork(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, signal_infork);
	}
}

void		signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "$->", 3);
		signal(SIGINT, signal_handler);
	}
}
