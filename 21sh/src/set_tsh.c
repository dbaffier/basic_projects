/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tsh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:04:29 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 16:04:52 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include "lexer.h"
#include "parse.h"
#include "execute.h"
#include "prompt.h"
#include "utils.h"
#include "terminal.h"
#include "builtins.h"
#include "ft_printf.h"
#include "free.h"

t_shglobal		*init_tsh(char **environ)
{
	t_shglobal	*shg;
	int			shlvl;
	char		*shl;

	if (!(shg = ft_memalloc(sizeof(t_shglobal))))
		exit(1);
	shg->env = first_clone(environ, 0);
	shlvl = ft_atoi(get_var("SHLVL", shg->env));
	shl = ft_strjoinfree("SHLVL=", ft_itoa(++shlvl), 2);
	change_var_value(shl, &shg->env);
	free(shl);
	shg->exit_status = 0;
	shg->arg_status = NULL;
	shg->pipe_f = 0;
	create_hlist(get_var("HOME", shg->env), 0);
	return (shg);
}

char			**init_prompt(t_shglobal *sh)
{
	char			**line;
	struct termios	save;
	int				cursor;

	if (!(line = ft_memalloc(sizeof(char **) * (4096))))
		exit(1);
	init_term(&save, sh->env);
	cursor = prompt();
	line[0] = get_line(cursor, cursor, 0);
	if (!check_quote(&(line[0])))
	{
		ft_freetab(&line);
		return (NULL);
	}
	save_history(line[0], get_var("HOME", sh->env));
	if (ft_strlen(line[0]))
	{
		if (!(line = is_heredoc(line)))
		{
			ft_freetab(&line);
			return (NULL);
		}
	}
	tcsetattr(0, TCSANOW, &save);
	return (line);
}

void			save_herc(t_tok *lst, char **argv)
{
	int		i;

	if (lst == NULL || argv == NULL || argv[0] == NULL || argv[1] == NULL)
		return ;
	i = 1;
	while (lst)
	{
		if (lst->type & DLESSER)
		{
			lst->herecdoc = argv[i];
			i++;
		}
		lst = lst->next;
	}
}

int				main_exec(char **line, t_shglobal *sh)
{
	t_lstastree	*exec_tree;
	t_lex		buff;

	bzero(&buff, sizeof(buff));
	if (lexer_build(*line, ft_strlen(*line), &buff, line) == -1)
		return (-1);
	save_herc(buff.llisttok, line);
	if (parse(&buff, &exec_tree, line, sh) != 0)
		return (-1);
	get_signal(0);
	execute_syntax_tree(exec_tree, sh, sh->save, line);
	destroy_syntax_tree(exec_tree);
	free_lst_tok(buff.llisttok);
	ft_freetab(&line);
	return (1);
}

int				main_loop(t_shglobal *shg)
{
	char	**line;

	while (1)
	{
		if ((line = init_prompt(shg)) == NULL)
			continue ;
		write(1, "\n", 1);
		if (main_exec(line, shg) == -1)
			continue ;
	}
}
