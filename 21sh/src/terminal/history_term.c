/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:11:57 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/18 10:27:53 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "prompt.h"

/*
** go up on history
*/

char	*tup(struct s_hlist **temp, int prom_len, char *line)
{
	char	*tmp;
	int		curline;

	curline = cur_line(prom_len + ft_strlen(line), tgetnum("co"));
	while (curline-- > 1)
		ft_putstr(tgetstr("up", NULL));
	clean_last_command(c_lines(ft_strlen(line), tgetnum("co"), prom_len));
	if ((tmp = ft_strdup(browse_up(&temp))))
	{
		while (ft_strcmp(tmp, line) == 0)
		{
			if (*temp && (*temp)->next)
			{
				free(tmp);
				tmp = ft_strdup(browse_up(&temp));
			}
			else
				break ;
		}
		ft_putstr(tmp);
		free(line);
		return (tmp);
	}
	return (line);
}

/*
** go down on history
*/

char	*tdown(struct s_hlist **temp, int prom_len, char *line)
{
	char	*tmp;
	int		curline;

	curline = cur_line(prom_len + ft_strlen(line), tgetnum("co"));
	while (curline-- > 1)
		ft_putstr(tgetstr("up", NULL));
	clean_last_command(c_lines(ft_strlen(line), tgetnum("co"), prom_len));
	if ((tmp = ft_strdup(browse_down(&temp))))
	{
		while (ft_strcmp(tmp, line) == 0 && tmp[0] != '\0')
		{
			if (*temp && (*temp)->next)
			{
				free(tmp);
				tmp = ft_strdup(browse_down(&temp));
			}
			else
				break ;
		}
		ft_putstr(tmp);
		free(line);
		return (tmp);
	}
	return (line);
}

void	clean_last_command(int cc_lines)
{
	remove_lines_after(1, cc_lines);
	ft_putstr(tgetstr("dl", NULL));
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, putch);
	prompt();
}
