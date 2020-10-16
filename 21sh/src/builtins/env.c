/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:19:10 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 16:15:16 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		env_builtin(t_shell *sh)
{
	int j;
	int	i;
	int count;

	j = -1;
	i = 1;
	count = count_options(sh);
	if (sh->argc > 1)
	{
		while (i <= count)
		{
			if (!illegal_option(sh->argv[i]))
				return (1);
			i++;
		}
		if (count == sh->argc - 1)
			return (0);
		return (parse_env(sh, count + 1, count));
	}
	else
	{
		while (*(*(sh->env) + (++j)))
			ft_putendl(*(*(sh->env) + j));
		return (0);
	}
}

int		env_exec(char **cmd, char **envp, char **environ)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid < 0)
	{
		p_err("Fork failed to create a new process.\n", NULL, NULL, 2);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
			use_bin_exec(cmd, envp, environ);
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, &i, 0);
	ft_freetab(&environ);
	return (1);
}

int		use_bin_exec(char **cmd, char **envp, char **environ)
{
	int			success;
	char		*path;
	char		*cwd;
	char		buff[4097];
	struct stat st;

	success = 0;
	cwd = getcwd(buff, 4096);
	if (lstat(cmd[0], &st) == 0 && (S_IFREG & st.st_mode) &&
		!(S_IXUSR & st.st_mode))
	{
		error_msg(cmd[0], 1);
		return (1);
	}
	else if ((get_var("PATH", environ) && (path = get_var("PATH", environ))) ||
			(get_var("PATH", envp) && (path = get_var("PATH", envp))))
		success = try_paths(path, cmd, success, environ);
	if (!success)
	{
		error_msg(cmd[0], 0);
		return (1);
	}
	return (0);
}

int		try_paths(char *path, char **args, int success, char **environ)
{
	char		**paths;
	char		*tmp1;
	char		*tmp2;
	struct stat st;
	int			i;

	i = -1;
	paths = ft_strsplit(path, ':');
	while (paths[++i])
	{
		tmp1 = ft_strjoin(paths[i], "/");
		tmp2 = ft_strjoin(tmp1, args[0]);
		if (lstat(tmp2, &st) == 0 && (S_IFREG & st.st_mode) &&
			!(S_IXUSR & st.st_mode))
		{
			success = 1;
			ft_putstr_fd("21sh: permission denied: ", 2);
			p_err(tmp2, NULL, NULL, 2);
		}
		(!execve(tmp2, args, environ)) ? (success = 1) : success;
		free(tmp1);
		free(tmp2);
	}
	ft_freetab(&paths);
	return (success);
}

void	error_msg(char *arg, int i)
{
	if (i)
	{
		ft_putstr_fd("21sh: permission denied: ", 2);
		p_err(arg, NULL, NULL, 2);
	}
	else
	{
		ft_putstr_fd("21sh: No such file or directory: ", 2);
		p_err(arg, NULL, NULL, 2);
	}
}
