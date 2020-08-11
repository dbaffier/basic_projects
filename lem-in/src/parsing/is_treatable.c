/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_treatable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:24:30 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/02 00:52:33 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static t_room		*get_rule(t_room *room)
{
	while (room && !(room->rules & RULES_END))
		room = room->next;
	return (room);
}
*/
/*int					is_treatable(t_path *pf, t_room *room, t_link *link)
{
	t_room	*tmp;
	t_room	*end;

	tmp = room;
	end = get_rule(room);
	//link->head = link->head->next;
	while (room && room != end)
	{
		room = room->link->head->link->head;
		sleep(1);
	}
	if (room != end)
		is_treatable(pf, tmp, link->next);
	else if (ft_strcmp(room->name, end->name) == 0)
		return (1);
	return (-1);
}*/
