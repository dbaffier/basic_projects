/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:01:01 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/15 14:21:24 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		count_envp(char ***env)
{
	int		i;
	char	**s;

	i = 0;
	s = *env;
	while (s[i])
		i++;
	return (i);
}

int		find_char(char *s, char c)
{
	int	i;

	i = 0;
	if (!s[0])
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int		is_value(char *var)
{
	int i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=' && var[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int		set_env(char *var, char ***env)
{
	char	*tmp;

	if (!is_value(var))
	{
		if (parse_var_name(var))
			return (1);
		if (!(get_var(var, *env)))
			add_var(var, env);
		else
			del_env_value(var, env);
	}
	else
	{
		if (parse_var_name(tmp = ft_strsub(var, 0, find_char(var, '='))))
		{
			free(tmp);
			return (1);
		}
		if (!(get_var(tmp, *env)))
			add_var_value(var, env);
		else
			change_var_value(var, env);
		free(tmp);
	}
	return (0);
}

char	***get_realloc(char ***env)
{
	int		i;
	int		c_env;
	char	**env_dup;

	i = 0;
	env_dup = NULL;
	c_env = count_envp(env);
	if (!(env_dup = malloc(sizeof(char **) * (c_env + 2))))
		return (NULL);
	while (i < c_env)
	{
		env_dup[i] = (*(*env + i));
		i++;
	}
	env_dup[i] = NULL;
	env_dup[i + 1] = NULL;
	free(*env);
	*env = env_dup;
	return (env);
}
