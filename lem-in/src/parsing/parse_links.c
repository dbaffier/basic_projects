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

#include "lem_in.h"

static t_room	*linked_room(t_room *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (room);
		room = room->next;
	}
	printf("%s\n", name);
	return (NULL);
}

static void		add_link(t_path *pf, t_room *room, char *name)
{
	t_link		*link;
	t_link		*curr;

	if (!(link = ft_memalloc(sizeof(t_link))))
		return ;
	curr = room->link;
	link->lkd_room = linked_room(pf->lst_room, name);
	link->idx = link->lkd_room->idx;
	if (curr == NULL)
		room->link = link;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = link;
	}
}

static void		create_link(t_path *pf, t_room *room, char *name)
{
	t_link		*l;

	l = room->link;
	while (l)
	{
		if (!ft_strcmp(l->lkd_room->name, name))
			return ;
		l = l->next;
	}
	add_link(pf, room, name);
	room->link_n++;
}

static int		get_link(t_path *pf, char *line)
{
	t_room	*room;
	char	*after;
	char	*prev;
	int		i;
	int		found;

	room = pf->lst_room;
	found = 0;
	after = ft_strchr(line, '-') + 1;
	if (*after == 0)
		return (-1);
	prev = fill_name(line, '-');
	i = 0;
	while (room)
	{
		if (!ft_strcmp(after, room->name) && ++found)
			create_link(pf, room, prev);
		if (!ft_strcmp(prev, room->name) && ++found)
			create_link(pf, room, after);
		if (found == 2)
			break ;
		room = room->next;
	}
	free(prev);
	return (found);
}

int				parse_link(t_path *pf, char *line)
{
	if (get_link(pf, line) != 2)
		return (-1);
	pf->p_room = 1;
	return (1);
} 
