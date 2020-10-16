/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:27 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/20 21:37:29 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** move cursor on the left
*/

void	tleft(int *cursor, int prom_len)
{
	if (*cursor > prom_len)
	{
		tputs(tgetstr("le", NULL), 1, putch);
		(*cursor)--;
	}
}

/*
** move cursor on the right
*/

void	tright(int *cursor, int len, int prom_len)
{
	int co;

	co = tgetnum("co");
	if (*cursor < len + prom_len)
	{
		if (*cursor % co == 0)
		{
			tputs(tgetstr("do", NULL), 1, putch);
			tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, putch);
		}
		else
			ft_putstr(tgetstr("nd", NULL));
		(*cursor)++;
	}
}

void	thome(int *cursor, int prom_len)
{
	char	*cmstr;
	int		curline;

	cmstr = tgetstr("ch", NULL);
	curline = cur_line(*cursor, tgetnum("co"));
	while (curline > 1)
	{
		ft_putstr(tgetstr("up", NULL));
		curline--;
	}
	tputs(tgoto(cmstr, 0, prom_len - 1), 1, putch);
	*cursor = prom_len;
}

void	tend(int *cursor, int clines, int len)
{
	int		col;
	char	*cmstr;
	int		curline;

	cmstr = tgetstr("ch", NULL);
	col = tgetnum("co");
	curline = cur_line(*cursor, col);
	while (curline < clines)
	{
		ft_putstr(tgetstr("do", NULL));
		curline++;
	}
	tputs(tgoto(cmstr, 0, (len + 11 - 1) % col), 1, putch);
	*cursor = len + 11;
}
