/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 04:20:11 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/15 04:57:18 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		solver(t_path *pf)
{
	int		path;
	int		var;
	int		save_var;
	t_road	*curr;

	path = 0;
	var = pf->road->next->size + 1;
	save_var = var;
	curr == pf->curr;
	while (path < pf->path_n)
	{
		//backtrack function with var = pf->road->size + 1 && mat_save
		var++;
	}
	while (curr->next)
		curr = curr->next;
	if (curr->size < pf->last_road)
		//replace previous set with curr
	if (save_var < pf->last_road)
		solver(pf);
	else
		return ;
}
