/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:16:48 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/27 16:15:01 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cmd_arg.h"

char				**get_path(char *path, char **envp)
{
	int		i;
	int		j;
	char	**p;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], path, ft_strlen(path)))
		{
			p = ft_strsplit(envp[i] + 5, ':');
			j = -1;
			while (p[++j])
			{
				tmp = p[j];
				p[j] = ft_strjoinch(tmp, '/');
				free(tmp);
			}
			return (p);
		}
	}
	return (NULL);
}

int					builtin_handler(char **cmd, char ***envp)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(g_builtin) / sizeof(*g_builtin))
	{
		if (cmd[0] && !ft_strcmp(g_builtin[i].s, cmd[0]))
		{
			g_builtin[i].builtin(cmd + 1, envp);
			ft_freetab(&cmd);
			return (1);
		}
		i++;
	}
	return (0);
}
