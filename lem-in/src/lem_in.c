/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:32:45 by dbaffier          #+#    #+#             */
/*   Updated: 2019/07/22 23:21:35 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

#ifndef DEBUG

static void		print_debug(t_room *lst, int ant, int size)
{
	(void)lst;
	(void)ant;
	(void)size;
}
#else

static void		print_debug(t_room *lst, int ant, int size)
{
	t_link	*l;

	ft_printf("nb ants = %d\n", ant);
	while (lst)
	{
		ft_printf("Room name : %s\n", lst->name);
		ft_printf("\t\t -> [%d] y -> [%d] with index : [%d]\n", lst->x, lst->y, lst->idx);
		l = lst->link;
		while (l)
		{
			ft_printf("\tConnected to : [%s] with index : %d\n", l->lkd_room->name, l->idx);
			l = l->next;
		}
		lst = lst->next;
	}
	printf("number of room : %d\n", size);
	(void)lst;
	(void)ant;
	(void)size;
}
#endif

int main(int ac, char **av)
{
	t_path	pf;


	(void)av;
	if (ac != 1)
		return (exit_error_main());
	ft_memset(&pf, 0, sizeof(pf));
	get_input(&pf);
	printf("Hey\n");
	//sleep(1);
	pf.end->idx = pf.size - 1;
	//printf("pf->start : [%s]\n", pf.start->name);
	mat(&pf, pf.lst_room);
	//printf("Aft\n");
//	grep_path(&pf);
	evaluate_path(&pf);
	print_debug(pf.lst_room, pf.ant_n, pf.size);
	t_road		*curr;

	curr = pf.road;
	/*while (curr)
	{
		for (int i = 0; i < curr->size; i++)
		{
			for (t_room *ptr = pf.lst_room; ptr; ptr = ptr->next)
			{
				if (ptr->idx == curr->rd[i])
					printf("%s ", ptr->name);
			}
		}
		curr = curr->next;
		printf("\n");
	}*/
	//printf("%d\n", pf.path_n);
	move_ant(&pf, pf.road);
	print_ant(&pf, pf.ant);
	//if (pf.start)
		//ft_printf("start : %s , x : %d y : %d with index %d\n", pf.start->name, pf.start->x, pf.start->y, pf.start->idx);
	//if (pf.end)
		//ft_printf("end : %s , x : %d y : %d \n", pf.end->name, pf.end->x, pf.end->y);
	return (0);
}
