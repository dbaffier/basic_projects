/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:25:19 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/18 19:08:39 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		cd_builtin(t_shell *sh)
{
	int		p;
	int		i;

	p = get_cd_options(sh);
	i = get_arg_index(sh);
	if (sh->argc - i == 0)
		return (cd_no_args(sh->env));
	else if (sh->argc - i == 1)
	{
		if (!ft_strcmp(sh->argv[i], "--"))
			return (cd_no_args(sh->env));
		else
			return (cd_one_arg(sh->argv[i], sh->env, p, NULL));
	}
	else if (sh->argc - i == 2)
		return (cd_two_args(sh->argv[i], sh->argv[i + 1], sh->env, p));
	else
		ft_putstr("cd: too many arguments\n");
	return (1);
}

int		cd_no_args(char ***env)
{
	change_env_value("OLDPWD", get_var("PWD", *env), env);
	change_env_value("PWD", get_var("HOME", *env), env);
	chdir(get_var("HOME", *env));
	return (0);
}

int		cd_one_arg(char *arg, char ***env, int p, char *tmp)
{
	char	*cwd;

	if (!ft_strcmp(arg, "-"))
		return (cd_go_back(env));
	else
	{
		if (chdir(arg))
			return (cd_access(arg));
		else
		{
			if ((cwd = getcwd(NULL, 0)) == NULL)
			{
				p_err("cd: error retrieving current directory: "
						"getcwd: No such file or directory", NULL, NULL, 2);
				return (0);
			}
			if (!p && ft_strcmp(arg, "..") && !is_slashs(arg))
				cwd = get_pwd(cwd, arg, tmp);
			change_env_value("OLDPWD", get_var("PWD", *env), env);
			change_env_value("PWD", cwd, env);
			free(cwd);
		}
	}
	return (0);
}

char	*get_pwd(char *cwd, char *arg, char *tmp)
{
	tmp = ft_replace_str(cwd,
			&cwd[ft_find_last_char(cwd, '/') + 1], arg);
	if (same_slashs(tmp, cwd))
	{
		free(tmp);
		tmp = cwd;
		cwd = ft_replace_str(cwd,
				&cwd[ft_find_last_char(cwd, '/') + 1], arg);
	}
	free(tmp);
	return (cwd);
}

int		cd_go_back(char ***env)
{
	char	*cwd;
	char	buff[4096 + 1];

	if (!get_var("OLDPWD", *env))
	{
		p_err("21sh: cd: OLDPWD no set\n", NULL, NULL, 2);
		return (1);
	}
	if ((cwd = getcwd(NULL, 0)) == NULL)
	{
		p_err("cd: error retrieving current directory: "
		"getcwd: No such file or directory", NULL, NULL, 2);
		return (1);
	}
	if (chdir(get_var("OLDPWD", *env)))
	{
		free(cwd);
		return (cd_access(get_var("OLDPWD", *env)));
	}
	change_env_value("OLDPWD", cwd, env);
	change_env_value("PWD", getcwd(buff, 4096), env);
	print_pwd(get_var("HOME", *env), get_var("PWD", *env));
	free(cwd);
	return (0);
}
