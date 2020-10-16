/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:49:32 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/21 20:53:54 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		unsetenv_builtin(t_shell *sh)
{
	int		i;
	int		j;

	i = 0;
	if (sh->argc == 1)
	{
		p_err("unsetenv: Too few arguments", NULL, NULL, 2);
		return (0);
	}
	while (sh->argv[++i])
	{
		j = -1;
		while (*(*(sh->env) + (++j)))
		{
			if (unset_env(sh, i, j) == 0)
				return (0);
		}
	}
	return (1);
}

int		get_valid_id(char *var)
{
	int i;

	i = 0;
	while (var[i])
	{
		if (!ft_isalnum(var[i]))
		{
			ft_putstr_fd((const char *)"21sh: unsetenv: `", 2);
			ft_putstr_fd(var, 2);
			ft_putstr_fd((const char *)"': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int		unset_env(t_shell *sh, int i, int j)
{
	char	*tmp;
	char	*tmp1;

	if (get_valid_id(sh->argv[i]) == 1)
		return (0);
	tmp = ft_strsub(*(*(sh->env) + j), 0, find_char(*(*(sh->env) + j), '='));
	tmp1 = ft_strsub(sh->argv[i], 0, find_char(sh->argv[i], '='));
	if (ft_strcmp(tmp, tmp1) == 0)
	{
		while (*(*(sh->env) + (j + 1)))
		{
			ft_strdel(&(*(*(sh->env) + j)));
			(*(*(sh->env) + j)) = NULL;
			*(*(sh->env) + j) = ft_strdup(*(*(sh->env) + (j + 1)));
			j++;
		}
		ft_strdel(&(*(*(sh->env) + j)));
		(*(*(sh->env) + j)) = NULL;
		free(tmp);
		free(tmp1);
		return (0);
	}
	free(tmp);
	free(tmp1);
	return (1);
}
