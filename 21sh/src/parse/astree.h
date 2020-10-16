/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:35:34 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:44:12 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H

# include "lexer.h"

enum
{
	NODE_PIPE = (1 << 0),
	NODE_BACKGRND = (1 << 1),
	NODE_SEQ = (1 << 2),
	NODE_REDIRECT_IN = (1 << 3),
	NODE_REDIRECT_OUT = (1 << 4),
	NODE_DREDIRECT_IN = (1 << 5),
	NODE_DREDIRECT_OUT = (1 << 6),
	NODE_CMDPATH = (1 << 7),
	NODE_ARGUMENT = (1 << 8),
	NODE_DATA = (1 << 9),
};

/*
** Tree with his type and 2 void * possibly t_cmd or t_redirection or himself
*/

struct				s_astree
{
	int						type;
	void					*left;
	void					*right;
};

/*
**	List of cmd with arguments
*/

struct				s_cmd
{
	int				type;
	char			*cmd;
	struct s_cmd	*next;
};

/*
** List of redirections or file agregation
*/

struct				s_redirection {
	int						type;
	int						fd;
	int						close;
	char					*herecdoc;
	char					*io_number;
	char					*target;
	struct s_redirection	*next;
};

/*
**	Typedef of all structure
*/

typedef struct s_lstastree		t_lstastree;
typedef struct s_astree			t_astree;
typedef struct s_cmd			t_cmd;
typedef struct s_redirection	t_redirection;

/*
**	linked list of binary tree aka t_astree *
*/

struct				s_lstastree
{
	t_astree			*tree;
	struct s_lstastree	*next;
};

/*
**	Prototypes
*/

void				exaust_operator(t_tok **lst, t_redirection **redir);
void				exaust_ionumber(t_tok **lst, t_redirection **redir);
void				exaust_cmd(t_tok **lst, t_cmd **cmd);

t_astree			*create_leaf(void);

t_cmd				*create_cmd(char *arg, int type);

t_redirection		*create_redir(char *io_n, char *target,
		char *herec, int type);

t_lstastree			*parse_lexer(t_tok **lst);

#endif
