/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:46:31 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/08 19:49:44 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shlvl(char ***env)
{
	char	*s;
	char	*s2;
	char	**tmp;

	if (!(s = get_var("SHLVL", *env)))
		return ;
	s2 = ft_itoa(ft_atoi(s) + 1);
	s = ft_strjoinfree("SHLVL=", s2, 2);
	tmp = ft_parse(s, count_w(s));
	free(s);
	setenv_builtin(tmp, env);
	ft_freetab(&tmp);
}

void	execute(char **cmds, char ***dup_env)
{
	int		i;
	char	**cmd;

	i = 0;
	while (cmds[i])
	{
		cmd = ft_parse(cmds[i], count_w(cmds[i]));
		if (cmd && cmd[0] && builtin_handler(cmd, dup_env))
			;
		else if (cmd && cmd[0] && cmd_exec(cmd, *dup_env))
			;
		else
			ft_freetab(&cmd);
		i++;
	}
}

char	*get_var_space(char *str, char **env)
{
	char	*tmp;
	char	*s;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		i++;
	tmp = ft_strndup(str, i);
	if (!(s = get_var(tmp, env)))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (s);
}

void	parse_d(char ***cmds, char ***env)
{
	int		i;
	int		j;
	char	**ptr;
	char	*tmp;
	char	*temp;

	i = -1;
	ptr = *cmds;
	while (ptr[++i])
	{
		j = -1;
		while (ptr[i][++j])
		{
			if (ptr[i][j] == '$')
			{
				if ((tmp = get_var_space(ptr[i] + j + 1, *env)))
				{
					temp = get_occ(ptr[i] + j);
					ptr[i] = ft_strreplace(ptr[i], temp, tmp);
					free(temp);
				}
			}
		}
	}
	*cmds = ptr;
}

int		main(int ac, char **av, char **envp)
{
	char		**cmds;
	char		**dup_env;

	(void)ac;
	(void)av;
	dup_env = clone(envp);
	shlvl(&dup_env);
	while (1)
	{
		write(1, "$->", 3);
		signal(SIGINT, signal_handler);
		cmds = check_line();
		parse_d(&cmds, &dup_env);
		execute(cmds, &dup_env);
		ft_freetab(&cmds);
	}
	ft_freetab(&dup_env);
	return (0);
}
