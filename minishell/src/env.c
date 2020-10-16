/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:07:53 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/06 11:14:03 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		env_builtin(char **cmd, char ***envp)
{
	int		i;

	(void)cmd;
	i = 0;
	while (*(*envp + i))
	{
		ft_putendl(*(*envp + i));
		i++;
	}
}
