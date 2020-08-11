/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:33:47 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/14 23:11:06 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_road	*erase_dup(t_path *pf, t_road *save, t_road *curr, t_road *new_next)
{
	/*for (t_road *r = pf->road; r; r = r->next)
	{
		for (int i = 0; i < r->size; i++)
			printf("%d-", r->rd[i]);
		printf("\n");
	}
	printf("------------------BEFORE DELETE---------------------\n\n");
	for (int i = 0; i < curr->size; i++)
		printf("%d-", curr->rd[i]);
	printf("\n");
	*/
	//sleep(2);
	if (curr == pf->road)
		pf->road = pf->road->next;
	else
		save->next = new_next;
	if (curr)
	{
		pf->cum = pf->cum - curr->size;
	//	printf("DELETED : [%d]\n", curr->size); 
		//sleep(1);
		free(curr->rd);
		free(curr);
	}
	pf->path_n--;
	return (save);
}

static int				check_each(t_path *pf, t_road *curr)
{
	int		i;
	int		j;
	t_road *save;
	t_road *road;

	save = curr;
	road = curr->next;
	while (road)
	{
		i = 1;
		if (road == curr && road->next)
			road = road->next;
		while (i < curr->size - 1)
		{
			j = 1;
			while (j < road->size - 1)
			{
				if (road->rd[i] == curr->rd[j])
				{
					erase_dup(pf, save, road, road->next);
					return (1);
				}
				j++;
			}
			i++;
		}
		save = road;
		road = road->next;
	}
	return (0);
}

int		handle_dup(t_path *pf)
{
	t_road *road;
	int		erase;

	road = pf->road;
	erase = 0;
	while (road)
	{
		if (check_each(pf, road))
			erase = 1;
		road = road->next;
	}
	return (erase);
}

/*void		handle_dup(t_path *pf)
  {
  t_road	*road;
  t_road	*save;
  t_road	*tmp;

  road = pf->road;
  save = NULL;
  while (road)
  {
  if (check_each(pf->road, road))
  {
  if ((tmp = erase_dup(pf, save, road, road->next)) != NULL)
  road = tmp;
  else 
  road = pf->road;
  pf->path_n--;
  }
  save = road;
  road = road->next;
  }
  }*/

int			direct_path(t_path *pf)
{
	t_road	*road;
	t_road	*save;
	t_road	*tmp;

	road = pf->road;
	save = NULL;
	while (road)
	{
		if (road->size != 1)
		{
			if ((tmp = erase_dup(pf, save, road, road->next)) != NULL)
				road = tmp;
			else
				road = pf->road;
			pf->path_n--;
		}
		save = road;
		if (road)
			road = road->next;
	}
	return (1);
}
