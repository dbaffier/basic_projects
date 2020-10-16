/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:02:06 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/17 13:34:35 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** func to delete chars in case of delete right or delete left
*/

void	remove_chars(char ***line, int i)
{
	if (i >= 0)
	{
		if ((**line)[i + 1])
		{
			while ((**line)[i + 1])
			{
				(**line)[i] = (**line)[i + 1];
				i++;
			}
			(**line)[i] = '\0';
		}
		else
			(**line)[i] = '\0';
	}
}

/*
** add chars to a line in case the cursor is not at the end of the line
*/

char	*add_chars(char *line, char ch, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_strnew(ft_strlen(line) + 1);
	while (j < i)
	{
		tmp[j] = line[j];
		j++;
	}
	tmp[j++] = ch;
	while (line[i])
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int		c_lines(int len, int co, int prom_len)
{
	int clines;

	if ((len + prom_len) % co > 1)
		clines = (len + prom_len) / co + 1;
	else
		clines = (len + prom_len) / co;
	return (clines);
}

int		cur_line(int cursor, int co)
{
	int cur_line;

	if (cursor % co > 0)
		cur_line = cursor / co + 1;
	else
		cur_line = cursor / co;
	return (cur_line);
}

void	add_line(int curline, int clines)
{
	int c;

	c = 0;
	while (curline <= clines)
	{
		ft_putstr(tgetstr("do", NULL));
		curline++;
		c++;
	}
	while (c)
	{
		ft_putstr(tgetstr("up", NULL));
		c--;
	}
}
