/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rights_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:16:56 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/14 13:52:03 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_dead(char ***env, char *path, char *cwd)
{
	char	*cwd2;
	char	buff[4096];

	if (is_home_set(env))
		return (1);
	cwd2 = getcwd(buff, 4096);
	if (cwd2 == NULL && cwd == NULL && ft_strcmp(path, ".."))
	{
		ft_printf("Current path does not exist\n");
		return (1);
	}
	return (0);
}

void	set_pwd_forward(char ***env)
{
	char	**tmp;
	char	buff[4097];
	char	*cwd;
	char	*s;

	cwd = getcwd(buff, 4096);
	s = ft_strjoin("PWD=", cwd);
	tmp = ft_parse(s, count_w(s));
	setenv_builtin(tmp, env);
	free(s);
	ft_freetab(&tmp);
}
