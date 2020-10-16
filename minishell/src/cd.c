/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:37:39 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/14 12:18:28 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		dir_change(char *path, char ***env, int f)
{
	char	buff[4097];
	char	*cwd;
	char	*tmp;

	cwd = getcwd(buff, 4096);
	tmp = NULL;
	if (path[0] == '$')
		tmp = get_var(path + 1, *env);
	if (path[0] != '$' && !chdir(path))
	{
		if (f)
			ft_putendl(get_var("OLDPWD", *env));
		dir_path(env, path, cwd);
	}
	else if (path[0] == '$' && !chdir(tmp))
		dir_path(env, tmp, cwd);
	else
	{
		if (access(path, F_OK) == -1)
			ft_printf("cd: no such file or directory: %s\n", path);
		else if (access(path, R_OK) == -1)
			ft_printf("cd: permission denied: %s\n", path);
	}
}

static void		tilde(char *path, char *home, char ***env)
{
	char	*new;

	if (*(path + 1))
		new = ft_strjoin(home, ft_strchr(path, '/'));
	else
		new = ft_strdup(home);
	dir_change(new, env, 0);
	free(new);
}

static	char	*old_new(char *path, char *to_find, char *new)
{
	int		i;
	int		len;
	char	*tmp;
	char	*new_path;

	if (!(ft_strstr(path, to_find)))
		return (NULL);
	i = 0;
	len = ft_strlen(to_find);
	while (path[i])
	{
		if ((tmp = ft_strnstr(path + i, to_find, len)))
		{
			if (ft_strchr(tmp, '/'))
			{
				new_path = ft_strjoin(new, ft_strchr(tmp, '/'));
				ft_strcpy(path + i, new_path);
			}
			else
				ft_strncpy(path + i, new, ft_strlen(path + i));
			return (path);
		}
		i++;
	}
	return (NULL);
}

static int		cd_to(char **cmd, char ***env)
{
	char	*cwd;
	char	*tmp;
	char	buff[4097];

	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_printf("cd: too many arguments\n");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = old_new(cwd, cmd[0], cmd[1])))
		{
			ft_printf("cd: string not in the pwd: %s\n", cmd[0]);
			return (1);
		}
		dir_change(tmp, env, 0);
		return (1);
	}
	return (0);
}

void			cd_builtin(char **cmd, char ***env)
{
	char	*home;

	if (!(home = get_var("HOME", *env)))
	{
		ft_printf("Home variable is not set \n");
		return ;
	}
	if (!cmd[0])
		dir_change(home, env, 0);
	else if (cmd[0][0] == '~')
		tilde(cmd[0], home, env);
	else if (cd_to(cmd, env))
		;
	else
	{
		if (ft_strequ(cmd[0], "--"))
			dir_change(home, env, 0);
		else if (cmd[0][0] == '-' && !cmd[0][1])
			dir_change(get_var("OLDPWD", *env), env, 1);
		else
			dir_change(cmd[0], env, 0);
	}
}
