/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:45:06 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 11:36:51 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include "utils.h"
#include <pwd.h>

char	**clone(char **envp)
{
	char	**clone;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	clone = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		clone[i] = ft_strdup(envp[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

char	**first_clone(char **envp, int i)
{
	char	**clone;

	if (!envp[0])
	{
		if (!(clone = init_env_i()))
			return (NULL);
	}
	else
	{
		while (envp[i])
			i++;
		clone = (char **)ft_memalloc(sizeof(char *) *
				(i + get_alloc_size(envp) + 1));
		i = -1;
		while (envp[++i])
			clone[i] = ft_strdup(envp[i]);
		if (get_alloc_size(envp) > 0)
		{
			if (!(clone = init_env(clone, envp, i)))
				return (NULL);
		}
		else
			clone[i] = NULL;
	}
	return (clone);
}

char	**init_env(char **clone, char **envp, int i)
{
	char			*tmp;
	const char		*homedir;

	if (!get_var("TERM", clone))
		clone[i++] = ft_strdup("TERM=xterm-256color");
	if (!get_var("PWD", envp))
	{
		tmp = ft_strjoin("PWD=", getcwd(NULL, 0));
		clone[i++] = ft_strdup(tmp);
		free(tmp);
	}
	if (!get_var("HOME", envp) && ((pw = getpwuid(getuid()))))
	{
		homedir = pw->pw_dir;
		tmp = ft_strjoin("HOME=", homedir);
		clone[i++] = ft_strdup(tmp);
		free(tmp);
	}
	else
		return (NULL);
	!get_var("SHLVL", envp) ? (clone[i++] = ft_strdup("SHLVL=0")) : 0;
	if (!get_var("_", envp))
		clone[i++] = ft_strdup("_=/usr/bin/env");
	clone[i] = NULL;
	return (clone);
}

int		get_alloc_size(char **envp)
{
	int	i;

	i = 0;
	if (!get_var("TERM", envp))
		i++;
	if (!get_var("SHLVL", envp))
		i++;
	if (!get_var("_", envp))
		i++;
	if (!get_var("PWD", envp))
		i++;
	if (!get_var("HOME", envp))
		i++;
	return (i);
}

char	**init_env_i(void)
{
	char			*tmp;
	const char		*homedir;
	int				i;
	char			**clone;

	i = 0;
	clone = (char **)ft_memalloc(sizeof(char *) * (6));
	clone[i++] = ft_strdup("TERM=xterm-256color");
	tmp = ft_strjoinfree("PWD=", getcwd(NULL, 0), 2);
	clone[i++] = ft_strdup(tmp);
	free(tmp);
	if ((pw = getpwuid(getuid())))
	{
		homedir = pw->pw_dir;
		tmp = ft_strjoin("HOME=", homedir);
		clone[i++] = ft_strdup(tmp);
		free(tmp);
	}
	else
		return (NULL);
	clone[i++] = ft_strdup("SHLVL=0");
	clone[i++] = ft_strdup("_=/usr/bin/env");
	clone[i] = NULL;
	return (clone);
}
