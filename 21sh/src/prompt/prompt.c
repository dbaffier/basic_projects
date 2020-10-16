/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:39:37 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 16:03:43 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "prompt.h"
#include "utils.h"

int		prompt(void)
{
	ft_putstr("\e[1;33m");
	ft_putstr("21sh-1.0$ ");
	ft_putstr("\e[0m");
	return (10 + 1);
}

int		q_prompt(void)
{
	char	*cwd;

	if ((cwd = getcwd(NULL, 0)))
	{
		ft_putstr("\ndquote> ");
		free(cwd);
		return (9);
	}
	else
		ft_putstr("error on pwd\n");
	return (0);
}

int		h_prompt(void)
{
	char	*cwd;

	if ((cwd = getcwd(NULL, 0)))
	{
		ft_putstr("\n> ");
		free(cwd);
		return (3);
	}
	else
		p_err("Error on pwd", NULL, NULL, 2);
	return (0);
}
