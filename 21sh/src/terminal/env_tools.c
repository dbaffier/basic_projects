/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:49:30 by tsisadag          #+#    #+#             */
/*   Updated: 2019/01/17 00:38:15 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** count env variables
*/

int		count_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

/*
** get value of environment variable
*/

char	*get_env2(char *name, char **envp)
{
	int i;
	int j;
	int c_env;

	i = 0;
	c_env = count_env(envp);
	while (i < c_env && envp[i])
	{
		j = 0;
		while (envp[i][j] && name[j] && envp[i][j] == name[j])
			j++;
		if (envp[i][j] && envp[i][j] == '=')
			return (&envp[i][j + 1]);
		i++;
	}
	return (NULL);
}
