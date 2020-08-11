/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 08:01:07 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 22:22:16 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static t_room	*linked_room(t_room *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

static void		add_link(t_id *id, t_room *room, char *name)
{
	t_link		*link;
	t_link		*curr;

	if (!(link = ft_memalloc(sizeof(t_link))))
		return ;
	curr = room->link;
	link->lkd_room = linked_room(id->room, name);
	if (curr == NULL)
		room->link = link;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = link;
	}
}

static void		create_link(t_id *id, t_room *room, char *name)
{
	t_link		*l;

	l = room->link;
	while (l)
	{
		if (!ft_strcmp(l->lkd_room->name, name))
			return ;
		l = l->next;
	}
	add_link(id, room, name);
}

static int		get_link(t_id *id, char *line)
{
	t_room	*room;
	char	*prev;
	int		i;
	int		found;

	room = id->room;
	found = 0;
	prev = ft_strcdup(line, '-');
	while (line && *line != '-')
		line++;
	line++;
	i = 0;
	while (room)
	{
		if (!ft_strcmp(line, room->name) && ++found)
			create_link(id, room, prev);
		if (!ft_strcmp(prev, room->name) && ++found)
			create_link(id, room, line);
		if (found == 2)
			break ;
		room = room->next;
	}
	free(prev);
	return (found);
}

int				parse_link(t_id *id, char *line)
{
	if (get_link(id, line) != 2)
		return (-1);
	return (1);
} 
