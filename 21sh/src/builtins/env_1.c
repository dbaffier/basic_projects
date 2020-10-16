/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:48:36 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 16:16:17 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		count_options(t_shell *sh)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (sh->argv[i])
	{
		if (sh->argv[i][0] == '-')
			count++;
		else
			return (count);
		i++;
	}
	return (count);
}

int		illegal_option(char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (s[i] != 'i')
		{
			ft_putstr_fd("env: illegal option -- ", 2);
			ft_putchar_fd(s[i], 2);
			p_err("usage: env [-] [i]\n       "
			"[name=value ...] [utility [argument ...]]", NULL, NULL, 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int		parse_env(t_shell *sh, int i, int count)
{
	int		j;
	char	**environ;

	environ = NULL;
	j = get_to_set(sh, i);
	if (j > 0 && sh->argv[j])
	{
		if (!(environ = malloc(sizeof(char **) * 1)))
			return (1);
		environ[0] = NULL;
		count -= 1;
		if (!(count + 1))
		{
			environ = clone(*(sh->env));
			while ((++count) + 1 < j)
				set_env(sh->argv[count + 1], &environ);
		}
		else
		{
			while ((++count) + 1 < j)
				set_env(sh->argv[count + 1], &environ);
		}
		return (env_exec(&sh->argv[j], *(sh->env), environ));
	}
	return (0);
}

int		get_to_set(t_shell *sh, int i)
{
	int		j;

	j = count_options(sh);
	while (sh->argv[i])
	{
		if (is_to_set(sh->argv[i]))
			i++;
		else
			break ;
	}
	if (!sh->argv[i])
	{
		if (j > 0)
			while (sh->argv[++j])
				ft_putendl(sh->argv[j]);
		else
			tmp_environ(sh, j);
		return (-1);
	}
	return (i);
}

int		is_to_set(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
