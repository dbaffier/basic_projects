/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_road.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:11:50 by dbaffier          #+#    #+#             */
/*   Updated: 2019/07/19 23:59:36 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		dup_tab_i(t_path *pf, t_road *new, int *search, int size)
{
	int		*rd;
	int		i;

	i = 0;
	if (!(rd = malloc(sizeof(int) * size + 1)))
		return ;
	new->size = size + 1;
	while (i < size)
	{
		rd[i] = search[i];
		i++;
	}
	rd[i] = pf->end->idx;
	new->rd = rd;
}

void	creat_road(t_path *pf, int *search)
{
	t_road		*new;
	t_road		*curr;

	if (!(new = ft_memalloc(sizeof(t_road))))
		return ;
	dup_tab_i(pf, new, search, pf->tail);
	if (pf->road == NULL)
		pf->road = new;
	else
	{
		curr = pf->road;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	pf->path_n = pf->path_n + 1;
	if (pf->path_n == 1)
		pf->min_road = pf->tail - 1;
	pf->last_road = pf->tail - 1;
	pf->road_save = new;
	pf->cum += new->size - 1;
}
