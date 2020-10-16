/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 09:49:48 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/05 21:57:01 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lexer.h"
# include "astree.h"
# include "execute.h"

int	parse(t_lex *buff, t_lstastree **syntax_tree, char **line, t_shglobal *shg);

#endif
