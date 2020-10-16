/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:57:16 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/13 11:52:27 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

static int		env_pos(char *str, char **env)
{
	int		i;
	char	*cpy;

	i = -1;
	while (env[++i])
	{
		cpy = ft_strchr(str, '=');
		if (!ft_strncmp(str, env[i], ft_abs((int)(str - cpy))))
			return (i);
	}
	return (i);
}

static void		realloc_env(char ***env, int size)
{
	char	**env_dup;
	int		i;

	env_dup = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (*(*env + i) && i < size)
	{
		env_dup[i] = ft_strdup(*(*env + i));
		i++;
	}
	ft_freetab(env);
	*env = env_dup;
}

static void		insert_env(char *str, char ***env)
{
	int			pos;
	char		*tmp;
	char		*s;

	if (NULL == (s = ft_strchr(str, '=')))
		return ;
	pos = env_pos(str, *env);
	if (*(*env + pos))
	{
		tmp = ft_strchr(*(*env + pos), '=');
		free(*(*env + pos));
		(*(*env + pos)) = ft_strdup(str);
	}
	else
	{
		realloc_env(env, pos + 1);
		*(*env + (pos)) = ft_strdup(str);
		*(*env + (pos + 1)) = NULL;
	}
}

void			setenv_builtin(char **cmd, char ***env)
{
	int		i;

	i = 0;
	if (cmd && cmd[0] && cmd[1] != NULL)
	{
		ft_putstr("setenv: Too many arguments.\n");
		return ;
	}
	if (!(cmd[i]))
		return (env_builtin(cmd, env));
	else
	{
		while (cmd[i])
		{
			insert_env(cmd[i], env);
			i++;
		}
	}
}
