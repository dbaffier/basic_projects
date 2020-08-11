/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:07:17 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/20 00:13:45 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

static void			attribute_road(t_path *pf, t_road *road, t_ant *ant, int delay)
{
	t_ant		*new;
	static int	name = 1;

	if (ant)
	{
		while (ant->next)
			ant = ant->next;
		if (!(new = (t_ant *)ft_memalloc(sizeof(t_ant))))
			return ;
		ant->next = new;
		new->road = road;
		new->delay = delay;
		new->name = name;
		new->i = 1;
		new->next = NULL;
	}
	else
	{
		if (!(pf->ant = (t_ant *)ft_memalloc(sizeof(t_ant))))
			return ;
		pf->ant->road = road;
		pf->ant->delay = delay;
		pf->ant->name = name;
		pf->ant->i = 1;
		pf->ant->next = NULL;
	}
	name++;
}

void			move_ant(t_path *pf, t_road *road)
{
	int			ants;
	int			delay;
	int			i;

	ants = 1;
	delay = 0;
	i = 1;
	sleep(1);
	while (ants < pf->ant_n - 1)
	{
		road = pf->road;
		while (road)
		{
			if (i == pf->path_n)
				i = 1;
			else
				i++;
			attribute_road(pf, road, pf->ant, delay);
			if (ants ==  pf->ant_n)
				break ; 
			ants++;
			road = road->next;
		}
		delay++;
	}
}

static char *print_name(t_room *room, int idx)
{
	while (room && room->idx != idx)
		room = room->next;
	return (room->name);
}

void		print_ant(t_path *pf, t_ant *ant)
{
	/*int i = 0;

	(void)pf;
	printf("path_n = %d\n", pf->path_n);
	sleep(1);
	while (ant)
	{
		printf("NAME = %d\n", ant->name);
		printf("DELAY = %d\n", ant->delay);
		printf("I = %d\n", ant->i);
		printf("ROAD = ");
		i = 0;
		while (i < ant->road->size)
		{
			printf("%d  ", ant->road->rd[i]);
			i++;
		}
		printf("\n\n");
		ant = ant->next;

	}*/
	int		ants;
	int		stop;
	int		i;

	ants = 0;
	stop = 1;
	i = 0;
	while (stop)
	{
		ant = pf->ant;
		while (ant)
		{
			if (ant->delay < 1 && ant->i < ant->road->size)
			{
				ft_printf("L%d-%s ", ant->name, print_name(pf->lst_room, ant->road->rd[ant->i]));
				ant->i = ant->i + 1;
			}
			if (ant->delay >= 1)
				ant->delay = ant->delay - 1;
			if (ant->next == NULL && ant->i == ant->road->size)
				stop = 0;
			ant = ant->next;
		}
		ft_printf("\n");
	}
}
