/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:08:37 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/22 23:28:28 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		mat(t_path *pf, t_room *room)
{
	t_link	*tmp;
	int		i;
	int		j;

	j = 0;
	if (!(pf->mat = (int **)ft_memalloc(sizeof(int *) * pf->size)))
		return ;
	if (!(pf->mat_save = (int **)ft_memalloc(sizeof(int *) * pf->size)))
		return ;
	while (room)
	{
		i = room->idx;
		if (!(pf->mat[i] = (int *)ft_memalloc(sizeof(int) * pf->size)))
			return ;
		if (!(pf->mat_save[i] = (int *)ft_memalloc(sizeof(int) * pf->size)))
			return ;
		tmp = room->link;
		while (tmp)
		{
			j = tmp->lkd_room->idx;
			pf->mat[i][j] = 1;
			pf->mat_save[i][j] = 1;
			tmp = tmp->next;
		}
		room = room->next;
	}
}

static int	pass(t_path *pf, int index, int *search)
{
	int		i;

	i = 0;
	while (i < pf->tail)
	{
		if (search[i] == index)
			return (0);
		if (search[i] == -1)
			return (1);
		i++;
	}
	return (1);
}

static void unset_mat(t_path *pf, int **mat, int *search)
{
	int		i;

	i = 0;
	while (i < pf->tail)
	{
		if (pf->path_n == 1)
			pf->mat_save[search[i]][pf->buff[i]] = 0;
		mat[search[i]][pf->buff[i]] = 0;
		i++;
	}

}

static int	eval_wtd(t_path *pf)
{
	int		line;

	if (pf->path_n == 0)
		return (0);
	line = (pf->ant_n / pf->path_n) + 1 + (pf->last_road - pf->min_road);
	if (line <= pf->wtd)
	{
		pf->wtd = line;
		return (0);
	}
	return (1);
}

static int	check_s(t_path *pf, int s)
{
	t_road *road;
	int		i;

	i = 0;
	road = pf->road;
	while (road)
	{
		while (i < road->size - 1)
		{
			if (road->rd[i] == s)
				return (0);
			i++;
		}
		road = road->next;
	}
	return (1);
}

static int	evaluate_road(t_path *pf, int index, int var, int *search, int **mat)
{
	int			s;

	s = 0;
	if (check_s(pf, index) == 0)
		return (0);
	if (pf->test == 1)
		return (2);
	if (index == pf->size - 1 && pf->tail == var)
	{
		creat_road(pf, search);
		unset_mat(pf, mat, search);
		if (eval_wtd(pf))
		{
			t_road	*r;

			r = pf->road;
			while (r && r->next && r->next->next)
				r = r->next;
			free(r->next->rd);
			free(r->next);
			pf->path_n -= 1;
	//	pf->last_road = r->size - 2;
			printf("r road : [%d]\n", r->size);
	//		pf->last_road = r->size - 2;
			r->next = NULL;
			return (-1);
		}
		pf->test = 1;
		if (pf->tail == 1)
			return (0);
		return (1);
	}
	if (pf->tail > var || pf->path_n == pf->ant_n)
		return (1);
	while (s < pf->size)
	{
		if (mat[index][s] == 1 && pass(pf, s, search))
		{
			search[pf->tail] = index;
			pf->buff[pf->tail] = s;
			pf->tail = pf->tail + 1;
			evaluate_road(pf, s, var, search, mat);
			pf->tail = pf->tail - 1;
			pf->buff[pf->tail] = -1;
			search[pf->tail] = -1;
		}
		s++;
	}
	return (1);
}

static int		path_valid(t_path *pf, int var, int **mat)
{
	int			search[var + 1];
	//int			*search;
	int			start;

	start = 1;
	ft_memset(search, 0, sizeof(search));
	pf->buff = ft_memalloc(sizeof(int) * var + 1);
	while (start < pf->size)
	{
		if (mat[0][start] == 1)
		{
			pf->test = 0;
			search[pf->tail] = 0;
			pf->buff[pf->tail] = start;
			pf->tail = 1;
			if (evaluate_road(pf, start, var, search, mat) == -1)
				return (-1);
		}
		start++;
	}
	return (1);
}

int		grep_path(t_path *pf, int **mat, int var)
{
	pf->wtd = pf->ant_n + 1;
	while (var <= pf->ant_n)
	{
		if (path_valid(pf, var, mat) == 0)
			return (direct_path(pf));
		if (eval_wtd(pf) == 1)
			break ;
		var++;
	}
	return (1);
}

static int		**dup_save(int **matrice, int size)
{
	int		**new;
	int		i;
	int		j;

	i = 0;
	new = malloc(sizeof(int *) * size);
	while (i < size)
	{
		j = 0;
		new[i] = malloc(sizeof(int) * size);
		while (j < size)
		{
			new[i][j] = matrice[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

static int		load(t_path *new, t_path *curr)
{
	new->ant_n = curr->ant_n;
	new->size= curr->size;
	new->path_n = 1;
	new->min_road = curr->min_road;
	new->last_road = curr->min_road;
	new->cum += curr->min_road + 2;
	new->road = ft_memalloc(sizeof(t_road));
	new->road->rd = curr->road->rd;
	new->road->size = curr->road->size;
	new->road->dup = curr->road->dup;
	new->road_save = new->road;
	new->road->next = NULL;
	new->ant = curr->ant;
	new->lst_room = curr->lst_room;
	new->start = curr->start;
	new->end = curr->end;
	return (1);
}

int		evaluate_path(t_path *pf)
{
	int		**cpy_mat;
	int		max_found;
	int		var;
	t_path	*new_pf;

	// need to copy old to new
	grep_path(pf, pf->mat, 1);
	cpy_mat = dup_save(pf->mat_save, pf->size);
	max_found = pf->last_road;
	var = pf->road->next->size + 1;
	//printf("var : [%d] --- max_found : [%d]\n", var, max_found);
	while (var < max_found)
	{
		if (!(new_pf = ft_memalloc(sizeof(t_path))))
			return (0);
		load(new_pf, pf);
		new_pf->mat = dup_save(cpy_mat, pf->size);
		grep_path(new_pf, new_pf->mat, var);
		//printf("Start ------------ road \n");
		for (t_road *r = new_pf->road; r; r = r->next)
		{
			//printf("ROad size : [%d]\n", r->size);
	//		for (int i = 0; i < r->size; i++)
		//		printf("%d-", r->rd[i]);
			if (r->next == NULL)
				new_pf->last_road = r->size - 2;
	//		printf("\n");
		}
		//printf("END OF ROAD\n");
	//	printf("New road : [%d] --- last->road [%d]\n", new_pf->last_road, pf->last_road);
		if (new_pf->last_road < pf->last_road)
		{
	//		sleep(2);
		//	printf("Enter in new\n");
			pf->road = new_pf->road;
			pf->last_road = new_pf->last_road;
			free(new_pf);
			// Neeed to set new t_path
			var = pf->road->next->size + 1;
		}
		else
			var++;
	}
	return (1);
}
