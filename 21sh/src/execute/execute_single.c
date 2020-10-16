/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:11:40 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:04:59 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "execute.h"
#include "free.h"
#include <fcntl.h>
#include "utils.h"
#include "redirections.h"

static int		set_tab(t_cmd *cmd, t_shell *shell)
{
	t_cmd		*tmp;
	size_t		i;

	i = 0;
	tmp = cmd;
	if (cmd == NULL || cmd->cmd == NULL || cmd->cmd[0] == 0)
		return (0);
	while (cmd && cmd->cmd && ++i)
		cmd = cmd->next;
	if (!(shell->argv = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while (tmp && tmp->cmd)
	{
		shell->argv[i] = ft_strdup(tmp->cmd);
		tmp = tmp->next;
		i++;
	}
	shell->argv[i] = NULL;
	shell->argc = i;
	return (1);
}

void			init_shell(t_astree *hook, t_shell *shell, char ***env)
{
	shell->env = env;
	shell->rd = hook->right;
	shell->cmd = hook->left;
	if (!set_tab(hook->left, shell))
		return ;
	if (shell->argv[0])
		shell->initial = ft_strdup(shell->argv[0]);
}

static int		fork_exec(t_shell *sh)
{
	pid_t		pid;
	int			ret;

	ret = 0;
	if ((ret = set_exec(sh)) == 1 || sh->argv == NULL || sh->argv[0] == NULL)
		return (ret);
	if ((ret = builtins(sh)) >= 0)
		return (ret);
	if ((ret = cmd_exec(sh)) != 1)
		return (ret);
	if ((pid = fork()) == -1)
		return (exit_err("Fork failed\n", EXIT_FAILURE));
	if (pid == 0)
	{
		if ((ret = execve(sh->argv[0], sh->argv, *(sh->env))) == -1)
			return (exit_err("execve fail", EXIT_FAILURE));
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &ret, 0);
	return (exit_status(ret, pid));
}

int				execute_start(t_astree *hook, t_shglobal *shg)
{
	t_shell		shell;
	int			exit_status;
	int			i;

	ft_bzero(&shell, sizeof(shell));
	shell.line = shg->line;
	init_shell(hook, &shell, &shg->env);
	i = -1;
	if (shell.rd)
	{
		while (++i < 10)
			shell.save_fd[i] = fcntl(i, F_DUPFD_CLOEXEC, 10);
		if ((open_redir(&shell)) == REDIR_ERROR)
		{
			free_shell(&shell);
			return (1);
		}
	}
	exit_status = fork_exec(&shell);
	if (shell.rd)
		restore_std_fd(shell.rd, shell.save_fd);
	get_last_arg(hook->left, shg);
	free_shell(&shell);
	return (exit_status);
}

int				execute_simple(t_astree *tree, t_shglobal *shg)
{
	int					exit_status;

	if (tree == NULL)
		return (1);
	expand_cmd(tree->left, shg);
	remove_quotes(tree->left);
	exit_status = execute_start(tree, shg);
	return (exit_status);
}
