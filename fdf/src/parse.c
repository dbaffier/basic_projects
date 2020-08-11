/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:20:55 by dbaffier          #+#    #+#             */
/*   Updated: 2020/01/03 14:26:22 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		add_tp(t_lug *lug, t_p *new)
{
	t_p		*cur;

	if (lug->cord == NULL)
		lug->cord = new;
	else
	{
		cur = lug->cord;
		while (cur && cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

static int		tp_create(t_lug *lug, char **line)
{
	int		*tab;
	int		i;
	t_p		*new;

	if (!(new = ft_memalloc(sizeof(t_p))))
		return (ERR_MALLOC);
	i = 0;
	while (line[i])
		i++;
	new->size = i;
	tab = malloc(sizeof(int) * i);
	while (i--)
	{
		tab[i] = ft_atoi(line[i]);
		free(line[i]);
	}
	new->line = tab;
	add_tp(lug, new);
	return (0);
}

int				parse(t_lug *lug, char *map)
{
	char	*line;
	char	**spl;
	int		fd;

	lug->progname = map;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (ERR_OPEN);
	while ((get_next_line(fd, &line)) > 0)
	{
		spl = ft_strsplitws(line);
		tp_create(lug, spl);
		lug->list_size = lug->list_size + 1;
		free(spl);
	}
	return (0);
}
