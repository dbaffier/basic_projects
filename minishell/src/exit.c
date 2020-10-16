/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:12:36 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/13 13:53:43 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_occ(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		i++;
	tmp = ft_strndup(str, i);
	return (tmp);
}

void	exit_builtin(char **cmd, char ***env)
{
	int		status;

	(void)env;
	status = 0;
	if (cmd && cmd[0] && cmd[1])
		ft_putstr("exit: Too many arguments\n");
	else if (cmd[0] && cmd[0][0] && ft_isdigit(cmd[0][0]))
		status = ft_atoi(cmd[0]);
	else if (cmd[0] && cmd[0][0] && !ft_isdigit(cmd[0][0]))
		ft_putstr("exit: numeric argument required\n");
	if (status)
		exit(status % 256);
	else if (status == 0)
		exit(0);
}
