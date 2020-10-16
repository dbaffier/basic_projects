/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:18:10 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/20 15:35:51 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		same_slashs(char *s1, char *s2)
{
	int i;
	int j;
	int cs1;
	int cs2;

	i = 0;
	j = 0;
	cs1 = 0;
	cs2 = 0;
	while (s1[i])
	{
		if (s1[i] == '/')
			cs1++;
		i++;
	}
	while (s2[j])
	{
		if (s2[j] == '/')
			cs2++;
		j++;
	}
	if (i == j)
		return (1);
	return (0);
}

int		cd_access(char *arg)
{
	ft_putstr("21sh: cd: ");
	if (access(arg, F_OK) == -1)
		ft_putstr("no such file or directory: ");
	else if (access(arg, R_OK) == -1)
		ft_putstr("permission denied: ");
	else
		ft_putstr("not a directory: ");
	ft_putendl(arg);
	return (1);
}

void	tmp_environ(t_shell *sh, int j)
{
	char	**environ;

	environ = NULL;
	environ = clone(*(sh->env));
	while (sh->argv[++j])
		set_env(sh->argv[j], &environ);
	while (environ[++j])
		ft_putendl(environ[j]);
	ft_freetab(&environ);
}
