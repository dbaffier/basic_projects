/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:16:48 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/17 16:21:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../inc/cmd_arg.h"

static char			*copy_n(char *str, char c)
{
	int		len;
	int		i;
	int		size;

	size = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[--len] != c)
		;
	str[len] = 0;
	return (str);
}

void				set_pwd_p(char *cwd, char ***env)
{
	char	*s;
	char	**tmp;

	s = ft_strdup(cwd);
	s = ft_strjoinfree("PWD=", copy_n(s, '/'), 2);
	tmp = ft_parse(s, count_w(s));
	setenv_builtin(tmp, env);
	free(s);
	ft_freetab(&tmp);
}

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
