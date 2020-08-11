/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:13:02 by mmonier           #+#    #+#             */
/*   Updated: 2019/08/04 21:02:59 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

size_t		ft_strclen(char c, char *line)
{
	size_t i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	return (i);
}

char		*ft_strcdup(char *line, char c)
{
	size_t	len;
	int		i;
	char	*str;

	len = ft_strclen(c, line);
	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (line[i] && line[i] != c)
	{
		str[i] = line[i];
		i++;
	}
	return (str);
}

static void	ant_n(t_id *id)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 0)
		return ;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return ;
		i++;
	}
	id->ant_n = ft_atoi(line);
}

static int	get_x(t_id *id, char *line)
{
	int		i;
	char	*str;

	i = 0;
	while(*line != 32)
		line++;
	line++;
	while (line[i] && line[i] != 32)
	{
		if (!(ft_isdigit(line[i])))
			return (-1);
		i++;
	}
	line[i] = '\0';
	return (ft_atoi(line));
}

static int	get_y(t_id *id, char *line)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (*line && y != 2)
	{
		if (*line == 32)
			y++;
		line++;
	}
	line++;
	while (line[i])
	{
		if (!(ft_isdigit(line[i])))
			return (-1);
		i++;
	}
	return (ft_atoi(line));
}

static void get_room(t_id *id, char *line)
{
	t_room *room;
	t_room *new;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return ;
	if (!(room->name = ft_strcdup(line, 32)))
		return ;
	room->x = get_x(id, line);
	room->y = get_y(id, line);
	room->next = NULL;
	new = id->room;
	if (!new)
		id->room = room;
	else
	{
		while (new->next)
			new = new->next;
		new->next = room;
		new->next->next = NULL;
	}
}

/*static void	set_link(t_id *id, t_room *room, char *link)
{
	t_room *search;
	t_room *new;

	if ((search = id->room) == NULL)
		return ;
	while (search && ft_strcmp(search->name, link) != 0)
	{
		printf(" LINK [%s] --- NAME [%s]\n", link, search->name);
		search = search->next;
	}
	printf("search %p\n", (void *)search);
	if (search && search->link == NULL)
	{
		printf("SEG\n");
		if (!(search->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return ;
		if (!(search->link->lkd_room = (t_room *)ft_memalloc(sizeof(t_room))))
			return ;
		search->link->lkd_room = room;
		printf("lkd_room->name = %s\n", search->link->lkd_room->name);
		search->link->lkd_room->next = NULL;
	}
	else
	{
		if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
			return ;
		new = room;
		while (search->link->lkd_room->next)
			search->link->lkd_room = search->link->lkd_room->next;
		search->link->lkd_room = room;
		search->link->lkd_room->next = NULL;
	}
}

static void	get_link(t_id *id, char *line)
{
	char	*first;
	t_room	*room;

	room = id->room;
	first = ft_strcdup(line, '-');
	while (line && *line != '-')
		line++;
	line++;
	while (room)
	{
		if (ft_strcmp(room->name, line) == 0)
			set_link(id, room, first);
		else if (ft_strcmp(room->name, first) == 0)
			set_link(id, room, line);
		room = room->next;	
	}
}
*/
static void	get_input(t_id *id)
{
	int		ret;
	char	*line;

	ret = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_count_occ(line, ' ') == 2)
			get_room(id, line);
		if (ft_count_occ(line, '-') == 1)
			parse_link(id, line);
		free(line);
	}
}

int			parse_input(t_id *id)
{
	ant_n(id);
	get_input(id);
	return (1);
}
