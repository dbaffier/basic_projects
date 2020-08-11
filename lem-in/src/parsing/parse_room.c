/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 06:13:17 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 22:10:00 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_y(char *line, int *pos)
{
	int res;

	res = 0;
	if (line[*pos] && !ft_isdigit(line[*pos]))
		return (-1);
	while (line[*pos])
	{
		if (!ft_isdigit(line[*pos]))
			return (-1);
		res = res * 10 + (line[*pos] - 48);
		(*pos)++;
	}
	return (res);
}

static int		get_x(char *line, int *pos)
{
	int res;

	res = 0;
	if (line[*pos] && !ft_isdigit(line[*pos]))
		return (-1);
	while (line[*pos] && line[*pos] != 32)
	{
		if (!ft_isdigit(line[*pos]))
			return (-1);
		res = res * 10 + (line[*pos] - 48);
		(*pos)++;
	}
	if (line[*pos] != 32)
		return (-1);
	(*pos)++;
	return (res);
}

static int		get_name(t_room *room, char *line, int *pos)
{
	while (line[*pos] && line[*pos] != 32)
		 (*pos)++;
	 if (line[*pos] != 32)
		 return (-1);
	room->name = fill_name(line, 32);
	(*pos)++;
	return (1);
}

static void		assign_rules(t_path *pf, t_room *room, int mask)
{
	if (mask == RULES_END)
		pf->end = room;
	if (mask == RULES_START)
	{
		pf->start = room;
		pf->start->idx = 0;
	}
	room->rules |= mask;
}

static t_room	*duplicate(t_room *room, t_room *name, int *dup)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name->name))
		{
			*dup = 1;
			break ;
		}
		room = room->next;
	}
	if (*dup)
	{
		free(name);
		return (room);
	}
	return (name);
}

int				parse_room(t_path *pf, char *line, char *name, int mask)
{
	t_room		*room;
	int			pos;
	int			ret;
	int			dup;

	pos = 0;
	dup = 0;
	if (line[0] == 'L')
		print_free(pf, line);
	pf->size = pf->size + 1;
	if (!(room = ft_memalloc(sizeof(t_room))))
		return (-1);
	room->idx = 0;
	ret = get_name(room, line, &pos);
	room = duplicate(pf->lst_room, room, &dup);
	room->x = get_x(line, &pos);
	room->y = get_y(line, &pos);
	if (ret < 0 || room->x < 0 || room->y < 0)
	{
		free(room);
		print_free(pf, line);
	}
	if (name)
	{
		free(room->name);
		room->name = name;
	}
	assign_rules(pf, room, mask);
	if (!dup)
		add_room(pf, room, mask);
	return (1);
}
