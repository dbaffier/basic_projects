/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 09:57:36 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:02:57 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

int		lexer_build(char *input, int size, t_lex *lexerbuf, char **line)
{
	int		k;
	t_tok	*token;
	t_tok	*save;

	ft_bzero(lexerbuf, sizeof(lexerbuf));
	if (lexerbuf == NULL)
		return (-1);
	if (size == 0)
		return (0);
	if (*input == '\\' && input[1] == 0)
	{
		ft_freetab(&line);
		return (-1);
	}
	if (!(lexerbuf->llisttok = ft_memalloc(sizeof(t_tok))))
		return (-1);
	save = lexerbuf->llisttok;
	token = lexerbuf->llisttok;
	handle_states(&token, input);
	token = save;
	k = 0;
	while (save != NULL && ++k)
		save = save->next;
	lexerbuf->ntoks = k;
	return (k);
}
