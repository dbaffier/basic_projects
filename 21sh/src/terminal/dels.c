/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dels.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:22:25 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/18 10:48:20 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "prompt.h"

/*
** delete characters on the left
*/

void	del_left(int *cursor, char **line, int prom_len)
{
	ft_putstr(tgetstr("le", NULL));
	ft_putstr(tgetstr("dc", NULL));
	remove_chars(&line, *cursor - prom_len - 1);
	remove_lines_after(cur_line(*cursor, tgetnum("co")),
		c_lines(ft_strlen(*line), tgetnum("co"), prom_len));
	(*cursor)--;
	if (*cursor % tgetnum("co") == 0)
	{
		tputs(tgoto(tgetstr("ch", NULL), 0, tgetnum("co") - 1), 1, putch);
		(*cursor >= (int)(ft_strlen(*line) - 1 + prom_len)) ?
			ft_putchar(' ') : 0;
	}
	else
		tputs(tgoto(tgetstr("ch", NULL), 0, *cursor % tgetnum("co") - 1),
			1, putch);
	ft_putstr(&(*line)[*cursor - prom_len]);
	pos_cursor(cur_line(*cursor, tgetnum("co")),
		c_lines(ft_strlen(*line) - 1, tgetnum("co"), prom_len));
	if (*cursor % tgetnum("co") == 0)
		tputs(tgoto(tgetstr("ch", NULL), 0, tgetnum("co") - 1), 1, putch);
	else if (*cursor % tgetnum("co") == 1)
		tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, putch);
	else
		tputs(tgoto(tgetstr("ch", NULL), 0, *cursor % tgetnum("co") - 1),
			1, putch);
}

/*
** delete characters on the right
*/

void	del_right(int cursor, char **line, int prom_len)
{
	int col;
	int curline;
	int	i;

	i = -1;
	col = tgetnum("co");
	curline = cur_line(cursor, col) + 1;
	if (cursor >= prom_len && cursor != (int)(ft_strlen(*line) + prom_len))
	{
		while (--curline > 1)
			ft_putstr(tgetstr("up", NULL));
		remove_lines_after(1, c_lines(ft_strlen(*line), col, prom_len));
		ft_putstr(tgetstr("dl", NULL));
		tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, putch);
		prompt();
		remove_chars(&line, cursor - prom_len);
		ft_putstr(*line);
		while (++i < (int)ft_strlen(&(*line)[cursor - prom_len]))
			ft_putstr(tgetstr("le", NULL));
		if ((ft_strlen(*line) - 1 + prom_len) % col == 1)
			ft_putstr(tgetstr("nd", NULL));
	}
}
