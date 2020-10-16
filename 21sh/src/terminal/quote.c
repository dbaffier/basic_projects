/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:42:17 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/20 17:42:50 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	is_quote(char *line, int i, int count)
{
	char	quote;

	quote = get_qquote(line, -1, 0);
	if (quote != '0')
	{
		while (line[i])
		{
			if (line[i + 1] && ((line[i] == '\\' && line[i + 1] == '\\') ||
						(line[i] == '\\' && line[i + 1] == quote)))
			{
				i += 2;
				continue;
			}
			if (line[i + 1] && line[i + 2] &&
			(line[i] == '\'' && line[i + 1] == '\\' && line[i + 2] == '\''))
			{
				i += 3;
				continue;
			}
			count = (line[i] == quote) ? (count + 1) : count;
			i++;
		}
	}
	quote = (!(count % 2)) ? '0' : quote;
	return (quote);
}

char	get_qquote(char *line, int i, int s)
{
	char	stock[2048];

	stock[0] = '0';
	while (line[++i])
	{
		if (line[i + 1] && ((line[i] == '\\' && line[i + 1] == '\\') ||
		(line[i] == '\\' && (line[i + 1] == '\'' || line[i + 1] == '\"'))
		|| (line[i] == '\'' && line[i + 1] == '\'')
		|| (line[i] == '\"' && line[i + 1] == '\"')))
			i += 2;
		else if (line[i + 1] && line[i + 2] &&
		(line[i] == '\'' && line[i + 1] == '\\' && line[i + 2] == '\''))
			i += 3;
		else if (line[i] == '\'' || line[i] == '\"')
		{
			if (s && stock[s - 1] == line[i])
				stock[--s] = '0';
			else
			{
				stock[s++] = line[i];
				stock[s] = '\0';
			}
		}
	}
	return (stock[0]);
}

int		check_quote(char **line)
{
	int		cursor;
	char	*quote_line;
	char	quote;

	while ((quote = is_quote(*line, 0, 0)) != '0')
	{
		cursor = q_prompt();
		quote_line = get_line_hq(cursor, cursor, 0);
		if (quote_line[0] == '\x3')
		{
			ft_putstr("\n");
			return (0);
		}
		if (quote_line[0] == '\x4')
		{
			ft_printf("21sh: unexpected EOF while looking for matching `%c'\n"
					"21sh: syntax error: unexpected end of file\n", quote);
			return (0);
		}
		*line = ft_strjoinfree(line[0], "\n", 1);
		*line = ft_strjoinfree(line[0], quote_line, 3);
	}
	return (1);
}
