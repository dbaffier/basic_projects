/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:55:16 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:09:38 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <termios.h>
# include "astree.h"
# include "stdlib.h"

# define PERM_DENIED		126
# define NO_FILE_DIR		127
# define NO_CMD				127
# define IS_DIR				126
# define IS_NO				-1

# define S_SEGFAULT		"segmentation fault"
# define S_FLOATING		"floating point exception"
# define S_BUS_ERROR	"bus error"
# define S_ABORT		"abort"

/*
**	Global struct to save data from past commands
*/

struct						s_shg
{
	int				exit_status;
	int				pipe_f;
	int				sigint;
	int				*save_fd;
	char			*arg_status;
	char			**env;
	char			**line;
	struct termios	*save;
};

/*
** Struct to handle tilde expansion
*/

struct						s_piped
{
	int				flag;
	int				pipread;
	int				*fds;
};

typedef struct s_piped		t_piped;

/*
**	Struct to stock everything commands related and env.
*/

struct						s_shell
{
	int				argc;
	int				save_fd[10];
	t_redirection	*rd;
	t_cmd			*cmd;
	t_piped			*piped;
	char			*initial;
	char			**argv;
	char			**line;
	char			***env;
};

typedef struct s_shell		t_shell;
typedef struct s_shg		t_shglobal;

t_shglobal					*init_tsh(char **environ);

int							builtins(t_shell *sh);
int							execute_pipe(t_astree *tree, t_shglobal *shg);
int							execute_simple(t_astree *tree, t_shglobal *shg);
int							clean_first_pipe(t_astree *tree, t_shglobal *shg,
		int fds[2], t_shell *shell);
int							cmd_exec(t_shell *sh);
int							open_redir(t_shell *sh);
int							set_exec(t_shell *sh);
int							exit_status(int status, pid_t pid);
int							exit_err(char *err, int status);
int							handle_redir(t_redirection *rd);
int							exec_first_pipe(t_shell *sh);
int							fill_pipe(int flag, int pipread,
		int *subfds, t_piped *piped);

void						init_shell(t_astree *hook, t_shell *shell,
		char ***env);
void						free_shell(t_shell *sh);
void						save_fd(int save[3]);
void						remove_quotes(t_cmd *lst);
void						expand_cmd(t_cmd *lst, t_shglobal *shg);
void						get_last_arg(t_cmd *cmd, t_shglobal *shg);
void						execute_redir(t_cmd *cmd,
		t_redirection *rd, char ***env);
void						execute_syntax_tree(t_lstastree *lst,
		t_shglobal *shg, struct termios *save, char **line);
void						get_signal(int sig);
t_shell						*init_first_pipe(t_astree *hook, t_shglobal *shg);
void						exec_next_pipe(t_astree *tree, t_shglobal *shg,
		int *fds, int *s);

#endif
