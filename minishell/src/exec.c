/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:03:31 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/04 21:02:49 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_builtin(char **cmd, char **env)
{
	struct stat		buf;

	if (cmd[0] && cmd[0][0] == '/')
	{
		if (stat(cmd[0], &buf) == 0)
			return (is_exec(cmd[0], buf, cmd, env));
	}
	return (0);
}

int			is_exec(char *path, struct stat f, char **cmd, char **envp)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (fork_exec(cmd, envp));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(path);
			ft_freetab(&cmd);
			return (1);
		}
		return (1);
	}
	return (0);
}

int			check_exec(char **cmd, char **env)
{
	char		*binary;
	char		**path;
	struct stat buf;
	int			i;

	i = -1;
	if (!(path = get_path("PATH=", env)))
		return (0);
	while (cmd[0] && path[++i])
	{
		if (!(binary = ft_strjoin(path[i], cmd[0])))
			return (0);
		if (stat(binary, &buf) == 0)
		{
			ft_freetab(&path);
			free(cmd[0]);
			cmd[0] = binary;
			return (is_exec(cmd[0], buf, cmd, env));
		}
		free(binary);
	}
	ft_freetab(&path);
	return (0);
}

int			cmd_exec(char **cmd, char **env)
{
	struct stat		buf;

	if (check_builtin(cmd, env) || check_exec(cmd, env))
		return (1);
	if (lstat(cmd[0], &buf) != -1)
	{
		if (buf.st_mode & S_IXUSR)
			return (fork_exec(cmd, env));
	}
	ft_printf("minishell: command not found: %s\n", cmd[0]);
	return (0);
}

int			fork_exec(char **cmd, char **envp)
{
	pid_t		pid;
	int			i;

	pid = fork();
	signal(SIGINT, signal_infork);
	if (pid < 0)
	{
		ft_freetab(&cmd);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	else if (pid == 0)
	{
		execve(cmd[0], cmd, envp);
		ft_freetab(&cmd);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &i, 0);
		ft_freetab(&cmd);
	}
	return (1);
}
