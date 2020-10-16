/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:22:15 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/05 17:01:01 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		find_prev_word(char *line, int index)
{
	index -= 2;
	while (index >= 0 && line[index])
	{
		if (line[index] == ' ' && line[index + 1] != ' ')
			return (index + 1);
		index--;
	}
	return (0);
}

int		find_next_word(char *line, int index)
{
	while (line[index])
	{
		if (line[index] == ' ' && line[index + 1] != ' ')
			return (index + 1);
		index++;
	}
	return (-1);
}

void	pos_cursor(int curline, int clines)
{
	while (curline < clines)
	{
		ft_putstr(tgetstr("up", NULL));
		curline++;
	}
}

void	pos_cursor_for_prompt(int curline, int clines)
{
	while (curline - 1 < clines)
	{
		ft_putstr(tgetstr("do", NULL));
		curline++;
	}
}

void	remove_lines_after(int curline, int clines)
{
	while (curline < clines)
	{
		ft_putstr(tgetstr("do", NULL));
		ft_putstr(tgetstr("dl", NULL));
		ft_putstr(tgetstr("up", NULL));
		curline++;
	}
}
