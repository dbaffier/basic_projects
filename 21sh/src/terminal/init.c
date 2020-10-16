/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:24:36 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/20 17:45:32 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** initialize termcaps
*/

int	init_term(struct termios *save, char **envp)
{
	int				ret;
	char			*term_name;
	struct termios	term;

	term_name = get_env2("TERM", envp);
	if (!term_name)
	{
		ft_printf("TERM must be set\n");
		return (-1);
	}
	if ((ret = tgetent(NULL, term_name)) == -1 || ret == 0)
	{
		(ret == -1) ? ft_printf("could not access termcap\n") :
		ft_printf("Terminal type is not defined in termcap\n");
		return (-1);
	}
	tcgetattr(0, &term);
	tcgetattr(0, save);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~ISIG;
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
