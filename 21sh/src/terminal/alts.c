/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:56:40 by tsisadag          #+#    #+#             */
/*   Updated: 2019/01/17 00:39:23 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** function to go up one line, on the key alt/option + up
*/

void	alt_up(int *cursor, int len, int prom_len)
{
	int co;
	int clines;
	int curline;

	co = tgetnum("co");
	clines = c_lines(len, co, prom_len);
	curline = cur_line(*cursor, co);
	if (curline > 1)
	{
		if (*cursor - co >= prom_len)
		{
			ft_putstr(tgetstr("up", NULL));
			*cursor -= co;
			tputs(tgoto(tgetstr("ch", NULL), 0, (*cursor % co) - 1), 1, putch);
		}
		else
		{
			ft_putstr(tgetstr("up", NULL));
			tputs(tgoto(tgetstr("ch", NULL), 0, prom_len - 1), 1, putch);
			*cursor = prom_len;
		}
	}
}

/*
** function to go down one line, on the key alt/option + down
*/

void	alt_down(int *cursor, int len, int prom_len)
{
	int co;
	int clines;
	int curline;

	co = tgetnum("co");
	clines = c_lines(len, co, prom_len);
	curline = cur_line(*cursor, co);
	if (curline < clines)
	{
		if (*cursor + co <= len + prom_len)
		{
			ft_putstr(tgetstr("do", NULL));
			*cursor += co;
			tputs(tgoto(tgetstr("ch", NULL), 0, (*cursor % co) - 1), 1, putch);
		}
		else
		{
			ft_putstr(tgetstr("do", NULL));
			tputs(tgoto(tgetstr("ch", NULL), 0, ((len + prom_len) % co) - 1), 1,
					putch);
			*cursor = (len + prom_len) % co;
		}
	}
}

/*
** function to go to the previous word, on the key alt/option + left
*/

void	alt_left(int *cursor, char *line, int prom_len)
{
	int i;
	int curline;
	int futline;
	int co;

	co = tgetnum("co");
	curline = cur_line(*cursor, co);
	i = find_prev_word(line, *cursor - prom_len);
	*cursor = i + prom_len;
	futline = cur_line(*cursor, co);
	if (curline == futline)
		tputs(tgoto(tgetstr("ch", NULL), 0, ((*cursor) % co) - 1), 1, putch);
	else
	{
		while (futline < curline)
		{
			ft_putstr(tgetstr("up", NULL));
			futline++;
		}
		tputs(tgoto(tgetstr("ch", NULL), 0, ((*cursor) % co) - 1), 1, putch);
	}
}

/*
** function to go to the next word, on key alt/option + right
*/

void	alt_right(int *cursor, char *line, int prom_len)
{
	int i;
	int curline;
	int futline;
	int co;

	co = tgetnum("co");
	curline = cur_line(*cursor, co);
	i = find_next_word(line, *cursor - prom_len);
	if (i == -1)
		*cursor = ft_strlen(line) + prom_len;
	else
		*cursor = i + prom_len;
	futline = cur_line(*cursor, co);
	if (curline == futline)
		tputs(tgoto(tgetstr("ch", NULL), 0, ((*cursor) % co) - 1), 1, putch);
	else
	{
		while (futline > curline)
		{
			ft_putstr(tgetstr("do", NULL));
			futline--;
		}
		tputs(tgoto(tgetstr("ch", NULL), 0, ((*cursor) % co) - 1), 1, putch);
	}
}
