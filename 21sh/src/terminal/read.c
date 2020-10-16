/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:29:39 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 17:06:01 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		putch(int c)
{
	ft_putchar(c);
	return (c);
}

int		exit_key(char b, char *line)
{
	if (b == 4 && !line[0])
	{
		free(line);
		return (1);
	}
	return (0);
}

char	*ret_condition(char b, char **line)
{
	if (b == '\x3')
	{
		free(*line);
		return ("\x3");
	}
	if (b == '\n')
		return (*line);
	if (exit_key(b, *line))
		return ("\x4");
	return (NULL);
}

char	*get_line(int cursor, int plen, int len)
{
	char				b[BUFF_SIZE];
	char				*line;
	struct s_hlist		*temp;

	temp = head;
	line = ft_strnew(1);
	get_signal(1);
	while (1)
	{
		ft_bzero(b, BUFF_SIZE);
		read(0, b, BUFF_SIZE - 1);
		if (b[0] == '\x3' || b[0] == '\n')
			return (line);
		if (exit_key(b[0], line))
			return ((line = ft_strdup("exit")));
		else if (TKEYS_1)
			t_keys(b, &cursor, plen, line);
		else if (UP || DOWN)
			line = (UP) ? tup(&temp, plen, line) : tdown(&temp, plen, line);
		else
			t_keys_2(b, &cursor, plen, &line);
		(UP || DOWN) ? cursor = plen + ft_strlen(line) : 0;
		len = ft_strlen(line);
	}
	return (line);
}

char	*get_line_hq(int cursor, int plen, int len)
{
	char				b[BUFF_SIZE];
	char				*line;
	struct s_hlist		*temp;

	temp = head;
	line = ft_strnew(1);
	get_signal(1);
	while (1)
	{
		ft_bzero(b, BUFF_SIZE);
		read(0, b, BUFF_SIZE - 1);
		if (b[0] == '\x3' || b[0] == '\n' || b[0] == '\x4')
			return (ret_condition(b[0], &line));
		else if (TKEYS_1)
			t_keys(b, &cursor, plen, line);
		else if (UP || DOWN)
			line = (UP) ? tup(&temp, plen, line) : tdown(&temp, plen, line);
		else
			t_keys_2(b, &cursor, plen, &line);
		(UP || DOWN) ? cursor = plen + ft_strlen(line) : 0;
		len = ft_strlen(line);
	}
	return (line);
}
