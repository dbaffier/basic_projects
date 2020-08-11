/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:50:58 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/04 00:00:44 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_room(t_path *pf, t_room *new, int mask)
{
	t_room		*curr;
	static int	curr_idx = 1;

	curr = pf->lst_room;
	if (!curr)
	{
		pf->lst_room = new;
		if (!mask)
			new->idx = curr_idx;
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		if (!mask)
			new->idx = curr_idx;
		curr->next = new;
		curr->next->next = NULL;
	}
	if (!mask)
		curr_idx += 1;
}
