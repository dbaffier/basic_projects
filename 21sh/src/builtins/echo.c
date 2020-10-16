/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:42:04 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/15 11:17:54 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		is_option_n(char *s)
{
	int i;

	i = 1;
	while (s[0] == '-' && s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int		echo_builtin(t_shell *sh)
{
	int		i;
	int		n;
	int		ret;

	i = 1;
	n = 0;
	while (sh->argv[i] && sh->argv[i][0] == '-' && is_option_n(sh->argv[i]))
	{
		n = 1;
		i++;
	}
	while (sh->argv[i])
	{
		if ((ret = echoo(sh->argv[i], sh->env)) == 1)
			return (1);
		(sh->argv[i + 1]) ? ft_putchar(' ') : 0;
		i++;
	}
	(sh->argc == 1 || n != 1) ? ft_putchar('\n') : 0;
	return (0);
}

int		echoo(char *s, char ***env)
{
	int i;

	(void)env;
	i = 0;
	while (s[i])
	{
		if ((write(1, &s[i], 1)) == -1)
		{
			p_err("21sh: echo: write error: bad file descriptor",
					NULL, NULL, 2);
			return (1);
		}
		i++;
	}
	return (0);
}
