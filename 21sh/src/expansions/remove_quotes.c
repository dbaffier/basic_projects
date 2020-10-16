/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:55:24 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/15 09:51:42 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

static char		found_quote(char c)
{
	char	found;

	found = 0;
	if (c == '\'')
		found = '\'';
	else if (c == '\"')
		found = '\"';
	return (found);
}

static void		clean_quotes(char *str)
{
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	while (str[i])
	{
		while ((quote = found_quote(str[i])))
		{
			ft_strcpy(str + i, str + i + 1);
			while (str[i] != quote)
				i++;
			ft_strcpy(str + i, str + i + 1);
		}
		i++;
	}
}

void			remove_quotes(t_cmd *lst)
{
	while (lst)
	{
		if (lst->cmd)
			clean_quotes(lst->cmd);
		lst = lst->next;
	}
}
