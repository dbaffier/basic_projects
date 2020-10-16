/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 06:36:48 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/07 19:39:46 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_ARG_H
# define CMD_ARG_H

t_call	g_builtin[] =
{
	{"echo", &echo_builtin},
	{"env", &env_builtin},
	{"setenv", &setenv_builtin},
	{"exit", &exit_builtin},
	{"unsetenv", &unsetenv_builtin},
	{"cd", &cd_builtin}
};

#endif
