/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:56:10 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/20 15:37:13 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	print_buff(char *b, int *cursor, char **line)
{
	char	*tmp;
	char	*tmp1;

	if (b[0])
	{
		tmp = *line;
		ft_putstr(b);
		*cursor += ft_strlen(b);
		tmp1 = ft_strjoin(*line, b);
		*line = ft_strdup(tmp1);
		free(tmp);
		free(tmp1);
	}
}

void	insert_buff(char *b, int *cursor, char **line, int prom_len)
{
	int		len;
	int		g;
	int		tmp;
	char	*tmp1;
	char	*tmp2;

	len = ft_strlen(*line);
	g = 1;
	tmp = 0;
	if ((len + prom_len - 1) % tgetnum("co") == 0)
	{
		add_line(cur_line(*cursor, tgetnum("co")),
				c_lines(len, tgetnum("co"), prom_len));
		tputs(tgoto(tgetstr("ch", NULL), 0, *cursor % tgetnum("co")), 1, putch);
	}
	tmp1 = *line;
	tmp2 = add_chars(*line, b[0], *cursor - prom_len);
	*line = ft_strdup(tmp2);
	free(tmp1);
	free(tmp2);
	ft_putstr(&(*line)[*cursor - prom_len]);
	tmp = *cursor;
	*cursor += ft_strlen(&(*line)[tmp - prom_len]);
	while (g++ < (int)ft_strlen(&(*line)[tmp - prom_len]))
		tleft(&(*cursor), prom_len);
}

void	t_keys(char *b, int *cursor, int prom_len, char *line)
{
	if (LEFT)
		tleft(&(*cursor), prom_len);
	else if (RIGHT)
		tright(&(*cursor), ft_strlen(line), prom_len);
	else if (ALTUP)
		alt_up(&(*cursor), ft_strlen(line), prom_len);
	else if (ALTDOWN)
		alt_down(&(*cursor), ft_strlen(line), prom_len);
	else if (ALTLEFT)
		alt_left(&(*cursor), line, prom_len);
	else if (ALTRIGHT)
		alt_right(&(*cursor), line, prom_len);
	else if (HOME)
		thome(&(*cursor), prom_len);
	else if (END)
		tend(&(*cursor), c_lines(ft_strlen(line), tgetnum("co"), prom_len),
				ft_strlen(line));
}

void	t_keys_2(char *b, int *cursor, int prom_len, char **line)
{
	if (TAB || SHIFT || EXIT)
		return ;
	else if (DELLEFT)
	{
		if (*cursor > prom_len)
			del_left(&(*cursor), (&(*line)), prom_len);
	}
	else if (DELRIGHT)
		del_right(*cursor, (&(*line)), prom_len);
	else if (b[0] && (int)(ft_strlen(*line) + prom_len) > *cursor)
		insert_buff(b, &(*cursor), (&(*line)), prom_len);
	else
		print_buff(b, &(*cursor), &(*line));
}
