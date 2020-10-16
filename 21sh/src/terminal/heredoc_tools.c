/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:15:37 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 17:02:06 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "prompt.h"
#include "execute.h"

int		count_hdoc_ws(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] && line[i + 1])
	{
		if (line[i] == '<' && line[i + 1] == '<')
		{
			if ((line[i - 1] && !(WHITESPACE(line[i - 1]))))
				count++;
			if ((line[i + 2] && !(WHITESPACE(line[i + 2]))))
				count++;
			i += 2;
		}
		i++;
	}
	return (count);
}

void	get_split_line(char *tmp, char **line)
{
	if (tmp && tmp[0])
	{
		free(*line);
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
}

int		put_ws_before(char *line, char **tmp, int i, int *j)
{
	if (line[i - 1] && !(WHITESPACE(line[i - 1])))
	{
		(*tmp)[(*j)++] = ' ';
		(*tmp)[(*j)++] = line[i];
		(*tmp)[(*j)++] = line[i + 1];
		return (1);
	}
	return (0);
}

void	copy_ex_ws(char *line, char **tmp, int *i, int *j)
{
	if (!(line[(*i) - 1] && !(WHITESPACE(line[(*i) - 1]))) &&
			!(line[(*i) + 2] && !(WHITESPACE(line[(*i) + 2]))))
	{
		(*tmp)[(*j)++] = line[(*i)];
		(*tmp)[(*j)++] = line[(*i) + 1];
	}
	*i += 2;
}

char	*split_hdoc(char *line, int count, int i, int j)
{
	char	*tmp;
	int		h;

	tmp = ft_strnew(ft_strlen(line) + count + 1);
	while (line[i])
	{
		if (line[i + 1] && line[i] == '<' && line[i + 1] == '<')
		{
			h = put_ws_before(line, &tmp, i, &j);
			if (line[i + 2] && !(WHITESPACE(line[i + 2])))
			{
				if (!h)
				{
					tmp[j++] = line[i];
					tmp[j++] = line[i + 1];
				}
				tmp[j++] = ' ';
			}
			copy_ex_ws(line, &tmp, &i, &j);
		}
		else
			tmp[j++] = line[i++];
	}
	get_split_line(tmp, &line);
	return (line);
}
