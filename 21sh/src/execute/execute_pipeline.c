/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:49:31 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 10:01:19 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include "lexer.h"
#include "ft_printf.h"
#include "execute.h"
#include <fcntl.h>
#include "utils.h"
#include "redirections.h"

static void		exec_dup_piped(t_shell *sh)
{
	if (sh->piped->pipread)
		dup2(sh->piped->pipread, STDIN_FILENO);
	else
	{
		close(sh->piped->fds[1]);
		dup2(sh->piped->fds[0], STDIN_FILENO);
	}
	if (sh->piped->flag)
	{
		close(sh->piped->fds[0]);
		dup2(sh->piped->fds[1], STDOUT_FILENO);
	}
}

static int		exec_fork_pipe(t_shell *sh)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	if (!(cmd_exec(sh)))
		return (EXIT_FAILURE);
	if ((pid = fork()) == -1)
		return (exit_err("Fork failed\n", EXIT_FAILURE));
	if (pid == 0)
	{
		exec_dup_piped(sh);
		if (exec_rd_pipe(sh->rd) == REDIR_ERROR)
			exit(REDIR_ERROR);
		if ((ret = builtins(sh)) >= 0)
			exit(ret);
		else if ((ret = execve(sh->argv[0], sh->argv, *sh->env)) == -1)
			return (exit_err("execve fail", EXIT_FAILURE));
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &ret, 0);
	return (exit_status(ret, pid));
}

static int		init_sh_pipe(t_astree *hook, t_shglobal *shg, t_piped *piped)
{
	t_shell		shell;
	int			exit_status;
	int			i;

	i = -1;
	ft_bzero(&shell, sizeof(shell));
	expand_cmd(hook->left, shg);
	remove_quotes(hook->left);
	init_shell(hook, &shell, &shg->env);
	shell.piped = piped;
	exit_status = exec_fork_pipe(&shell);
	close_pipe_rd(shell.rd);
	free_shell(&shell);
	free(shell.piped);
	return (exit_status);
}

void			exec_next_pipe(t_astree *tree, t_shglobal *shg,
		int *fds, int *s)
{
	t_piped		*piped;
	int			status;
	int			pipread;
	int			subfds[2];

	status = 0;
	close(fds[1]);
	pipread = 0;
	piped = ft_memalloc(sizeof(t_piped));
	if (tree->right)
	{
		pipread = fds[0];
		if (fill_pipe(1, pipread, subfds, piped) == -1)
			return ;
		*s = init_sh_pipe(tree->left, shg, piped);
		exec_next_pipe(tree->right, shg, subfds, s);
		close(subfds[0]);
	}
	else
	{
		piped->fds = fds;
		*s = init_sh_pipe(tree->left, shg, piped);
	}
}

int				execute_pipe(t_astree *tree, t_shglobal *shg)
{
	t_shell		*shell;
	pid_t		pid;
	int			fds[2];
	int			status;

	status = 0;
	if (init_rd_pipe(tree) != REDIR_OK)
		return (1);
	if (pipe(fds) == -1)
		return (1);
	shell = init_first_pipe(tree->left, shg);
	if ((pid = fork()) == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		exec_first_pipe(shell);
	}
	else if (pid > 0)
	{
		status = clean_first_pipe(tree, shg, fds, shell);
		waitpid(pid, NULL, 0);
	}
	return (status);
}
