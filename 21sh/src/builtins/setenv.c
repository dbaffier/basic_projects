/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:23:41 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/21 20:20:38 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		setenv_builtin(t_shell *sh)
{
	char	*tmp;
	int		i;
	int		ret;

	i = 1;
	tmp = NULL;
	if (sh->argc == 1)
		return (env_builtin(sh));
	else
	{
		if (sh->argc == 2)
		{
			ret = set_env(sh->argv[i], sh->env);
			return (ret);
		}
		else if (sh->argc > 2)
			p_err("setenv: too many arguments", NULL, NULL, 2);
		return (1);
	}
	return (0);
}

char	***add_var(char *var, char ***env)
{
	int		count;
	char	***save;

	save = env;
	get_realloc(env);
	count = count_envp(env);
	if (var[ft_strlen(var) - 1] == '=')
		*(*env + (count)) = ft_strdup(var);
	else
		*(*env + (count)) = ft_strjoin(var, "=");
	return (env);
}

char	***del_env_value(char *var, char ***env)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = 0;
	while (*(*env + (i)))
	{
		tmp = ft_strsub(*(*env + (i)), 0, find_char(*(*env + (i)), '='));
		tmp1 = ft_strsub(var, 0, find_char(var, '='));
		if (ft_strcmp(tmp, tmp1) == 0)
		{
			ft_strdel(&(*(*env + (i))));
			*(*env + (i)) = NULL;
			*(*env + (i)) = ft_strjoin(tmp1, "=");
			free(tmp);
			free(tmp1);
			return (env);
		}
		free(tmp);
		free(tmp1);
		i++;
	}
	return (env);
}

char	***add_var_value(char *var, char ***env)
{
	int	count;

	count = count_envp(env);
	get_realloc(env);
	count = count_envp(env);
	*(*env + (count)) = ft_strdup(var);
	return (env);
}

char	***change_var_value(char *var, char ***env)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = 0;
	while (*(*env + (i)))
	{
		tmp = ft_strsub(*(*env + (i)), 0, find_char(*(*env + (i)), '='));
		tmp1 = ft_strsub(var, 0, find_char(var, '='));
		if (ft_strcmp(tmp, tmp1) == 0)
		{
			ft_strdel(&(*(*env + (i))));
			*(*env + (i)) = NULL;
			*(*env + (i)) = ft_strdup(var);
			ft_strdel(&tmp);
			ft_strdel(&tmp1);
			return (env);
		}
		ft_strdel(&tmp);
		ft_strdel(&tmp1);
		i++;
	}
	return (env);
}
