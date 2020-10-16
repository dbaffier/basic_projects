/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:12:36 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:54:43 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"
#include "terminal.h"

static void		free_hlist(struct s_hlist *lst)
{
	if (lst)
	{
		free(lst->line);
		free_hlist(lst->next);
		free(lst);
	}
}

void			exit_error_255(char *s)
{
	ft_putstr_fd("21sh: exit: ", 2);
	ft_putstr_fd(s, 2);
	p_err(": numeric argument required", NULL, NULL, 2);
	exit(255);
}

int				exit_builtin(t_shell *sh)
{
	ft_putstr("exit\n");
	if (sh->argc >= 2 && !ft_isdigits(sh->argv[1]))
		exit_error_255(sh->argv[1]);
	(sh->argc >= 3) ? ft_putstr("21sh: exit: too many arguments\n") : 0;
	if (sh->argc == 2)
	{
		(ft_atoi(sh->argv[1]) > 255) ? exit(ft_atoi(sh->argv[1]) % 256) : 0;
		if (ft_atoi(sh->argv[1]) < 0)
		{
			(ft_atoi(sh->argv[1]) < -255) ?
				exit(256 + ft_atoi(sh->argv[1]) % 256) : 0;
			exit(256 + ft_atoi(sh->argv[1]));
		}
		exit(ft_atoi(sh->argv[1]));
	}
	if (sh->argc == 1)
	{
		free_hlist(head);
		free_shell(sh);
		exit(0);
	}
	return (0);
}
