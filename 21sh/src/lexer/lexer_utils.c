/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:31:26 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 14:28:08 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void			set_token(t_tok **token, char *data, int *pos)
{
	if (data != NULL && ft_strcmp(data, " ") != 0)
	{
		if (*pos > 0)
		{
			(*token)->data[*pos] = 0;
			*pos = 0;
			fill_tok(token, data, 1);
		}
		else
			fill_tok(token, data, 0);
	}
	else
	{
		if (*pos > 0)
		{
			(*token)->data[*pos] = 0;
			*pos = 0;
		}
	}
}

static void			go_tonext(t_tok **token, char *input, char c)
{
	int		len;

	len = ft_strlen(input);
	if (len != 0 && c != ' ')
	{
		if (!((*token)->next = ft_memalloc(sizeof(t_tok))))
			exit(2);
		*token = (*token)->next;
	}
}

static int			prior_token(char *input, char **str)
{
	return (((*str = get_token(input, get_tokdup(input))) != input));
}

void				handle_states(t_tok **token, char *input)
{
	char		*data;
	int			pos;

	pos = 0;
	while (input && *input == ' ')
		input++;
	while (*input)
	{
		if ((prior_token(input, &data)))
		{
			set_token(token, data, &pos);
			input += ft_strlen(data);
			free(data);
			go_tonext(token, input, *input);
		}
		else
			h_wordtok(token, &input, &pos);
	}
}
