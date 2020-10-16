/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:58 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 10:02:06 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

# include "execute.h"

/*
** Enum for TILDE expansion
*/

enum
{
	TILDE_USER = 00000010,
	TILDE_PLUS = 00000100,
	TILDE_LESS = 00001000,
	TILDE_NO = 00010000,
	TILDE_QUOTED = 00100000,
	TILDE_SOLO = 01000000,
};

struct							s_tilde
{
	int				flags;
	char			*prefix;
	struct passwd	*user;
};

typedef struct s_tilde			t_tilde;

void							get_prefix(char *str, t_tilde *tilde);

char							*expand_special(char c, t_shglobal *shg);
char							*add_string(char *s1, char *s2, int flags);
char							*add_expand(char *s1, char *s2, int flags);
char							*search_expand(char *expand, t_shglobal *shg);
char							*expand_tilde(char *str, char ***env);
char							*expand_dollar(char *s, t_shglobal *shg);

#endif
