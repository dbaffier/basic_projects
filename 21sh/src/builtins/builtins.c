/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:42:33 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/05 19:12:13 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "builtins.h"
#include "ft_printf.h"

int		builtins(t_shell *sh)
{
	unsigned int	i;
	static t_call	tab[] =
	{{"echo", &echo_builtin},
	{"env", &env_builtin},
	{"setenv", &setenv_builtin},
	{"exit", &exit_builtin},
	{"unsetenv", &unsetenv_builtin},
	{"cd", &cd_builtin}};

	if (sh->argv == NULL || sh->argv[0] == NULL)
		return (-1);
	i = 0;
	while (i < sizeof(tab) / sizeof(*tab))
	{
		if (sh->argv[0] && !ft_strcmp(tab[i].s, sh->argv[0]))
			return (tab[i].builtin(sh));
		i++;
	}
	return (-1);
}
