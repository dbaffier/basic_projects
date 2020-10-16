/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:23:32 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/17 16:19:33 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				get_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		i++;
	return (i);
}

int				is_home_set(char ***env)
{
	if (!(get_var("HOME", *env)))
	{
		ft_printf("%s variable is not set\n", "HOME");
		return (1);
	}
	return (0);
}

void			dir_path(char ***env, char *path, char *cwd)
{
	char	**tmp;
	char	buff[4097];
	char	*s;

	if (check_dead(env, path, cwd))
		return ;
	if (cwd == NULL && ft_strcmp(path, "..") == 0)
		if (!(cwd = getcwd(buff, 4096)))
		{
			ft_printf("Error cwd\n");
			return ;
		}
	if (ft_strcmp(path, "..") == 0)
		set_pwd_p(cwd, env);
	else
		set_pwd_forward(env);
	if (cwd)
	{
		s = ft_strjoin("OLDPWD=", cwd);
		tmp = ft_parse(s, count_w(s));
		free(s);
		setenv_builtin(tmp, env);
		ft_freetab(&tmp);
	}
}

void			echo_builtin(char **cmd, char ***env)
{
	int		i;
	int		j;

	(void)env;
	if (!cmd[0])
	{
		write(1, "\n", 1);
		return ;
	}
	i = !ft_strcmp(cmd[0], "-n") ? 0 : -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
			ft_putchar(cmd[i][j]);
		if (cmd[i + 1])
			write(1, " ", 1);
	}
	if (ft_strcmp(cmd[0], "-n"))
		write(1, "\n", 1);
}
