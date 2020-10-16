/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_first_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:24:55 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:46:29 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include "lexer.h"
#include "ft_printf.h"
#include "execute.h"
#include <fcntl.h>
#include "utils.h"
#include "redirections.h"

int				exec_first_pipe(t_shell *sh)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	if (!(cmd_exec(sh)))
		return (EXIT_FAILURE);
	if (exec_rd_pipe(sh->rd) == REDIR_ERROR)
		exit(REDIR_ERROR);
	if ((ret = builtins(sh)) >= 0)
		exit(ret);
	else if ((ret = execve(sh->argv[0], sh->argv, *sh->env)) == -1)
		return (exit_err("execve fail", EXIT_FAILURE));
	exit(EXIT_FAILURE);
	return (exit_status(ret, pid));
}

t_shell			*init_first_pipe(t_astree *hook, t_shglobal *shg)
{
	t_shell		*shell;
	int			i;

	i = -1;
	if (!(shell = ft_memalloc(sizeof(t_shell))))
		return (NULL);
	expand_cmd(hook->left, shg);
	remove_quotes(hook->left);
	init_shell(hook, shell, &shg->env);
	return (shell);
}

int				clean_first_pipe(t_astree *tree, t_shglobal *shg,
		int fds[2], t_shell *shell)
{
	int		status;

	status = 0;
	close_pipe_rd(shell->rd);
	free_shell(shell);
	free(shell);
	tree = tree->right;
	close(fds[1]);
	exec_next_pipe(tree, shg, fds, &status);
	close(fds[0]);
	return (status);
}
