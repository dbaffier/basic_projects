/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 09:52:41 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:52:46 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ft_printf.h"

# define WORD		(1 << 0)
# define OPERATOR	(1 << 1)
# define IO_NUMBER	(1 << 2)

enum
{
	IN_QUOTE = 1,
	IN_DQUOTE = 2,
};

enum
{
	GREATER_AMPERSAND = (1 << 0),
	LESSER_AMPERSAND = (1 << 1),
	LESS_GREATER = (1 << 2),
	PIPE = (1 << 3),
	SEMICOLON = (1 << 4),
	GREATER = (1 << 5),
	DGREATER = (1 << 6),
	LESSER = (1 << 7),
	DLESSER = (1 << 8),
};

# define OPE_GREAT_AND		{ ">&"	, GREATER_AMPERSAND }
# define OPE_LESS_AND		{ "<&"	, LESSER_AMPERSAND }
# define OPE_LESS_GREAT		{ "<>"	, LESS_GREATER }
# define OPE_PIPE			{ "|"	, PIPE }
# define OPE_SEMICOLON		{ ";"	, SEMICOLON }
# define OPE_GREATER		{ ">"	, GREATER }
# define OPE_DGREATER		{ ">>"	, DGREATER }
# define OPE_LESSER			{ "<"	, LESSER }
# define OPE_DLESSER		{ "<<"	, DLESSER }

typedef struct s_token		t_tok;
typedef struct s_lexer		t_lex;
typedef struct s_ope		t_ope;

struct						s_ope
{
	char			*name;
	size_t			value;
};

struct						s_token
{
	char			*data;
	int				operator;
	char			*herecdoc;
	int				type;
	struct s_token	*next;
};

struct						s_lexer
{
	t_tok			*llisttok;
	int				ntoks;
};

char						*get_token(char *start, const char *end);
char						*get_quote(char *str);
char						*get_tokdup(char *str);

int							get_chartype(char c);
int							identify_operator(const char *s);
int							lexer_build(char *input, int size,
		t_lex *lexerbuf, char **line);

void						alone_tok(t_tok **token, char data, int *pos);
void						h_wordtok(t_tok **token, char **input, int *pos);
void						fill_tok(t_tok **tok, char *data, int f);
void						lexer_destroy(t_lex *lexerbuf);
void						tok_destroy(t_tok *tok);
void						tok_init(t_tok *tok, int datasize);
void						free_test(t_tok *tok);
void						handle_states(t_tok **tok, char *input);

#endif
