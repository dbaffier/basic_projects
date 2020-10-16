/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:54:18 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 15:50:48 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		cd_two_args(char *arg1, char *arg2, char ***env, int p)
{
	int		i;
	char	*cwd;
	char	*rep;

	if (!(cwd = getcwd(NULL, 0)))
	{
		p_err(CD_ERR, NULL, NULL, 2);
		free(cwd);
		return (0);
	}
	if (ft_strstrn(cwd, arg1) == -1)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		p_err(arg1, NULL, NULL, 2);
		free(cwd);
		return (1);
	}
	else
	{
		rep = ft_replace_str(cwd, arg1, arg2);
		free(cwd);
		i = cd_one_arg(rep, env, p, NULL);
		free(rep);
		return (i);
	}
}

int		get_cd_options(t_shell *sh)
{
	int i;
	int p;
	int	ret;

	i = 1;
	p = 0;
	while (sh->argv[i] && (ret = is_symlnk_option(sh->argv[i])))
	{
		if (ret > 1)
			p = 1;
		i++;
	}
	return (p);
}

int		get_arg_index(t_shell *sh)
{
	int i;

	i = 1;
	while (sh->argv[i] && is_symlnk_option(sh->argv[i]))
		i++;
	return (i);
}

int		is_symlnk_option(char *s)
{
	int i;
	int p;
	int	l;

	i = 1;
	p = 0;
	l = 0;
	if (s[0] == '-' && s[1])
	{
		while (s[i])
		{
			if (s[i] != 'L' && s[i] != 'P')
				return (0);
			if (s[i] == 'P')
				p = 2;
			if (s[i] == 'L')
				l = 1;
			i++;
		}
		return (p + 1);
	}
	return (0);
}

int		is_slashs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '/')
			return (0);
		i++;
	}
	return (1);
}
