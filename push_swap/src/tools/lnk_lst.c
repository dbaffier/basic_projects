/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnk_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 04:18:11 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/28 12:42:26 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_insert(t_pile **a, int n)
{
	t_pile		*node;
	t_pile		*curr;

	if (!(node = (t_pile *)ft_memalloc(sizeof(t_pile))))
		exit(1);
	node->n = n;
	node->id = 1;
	node->next = node;
	node->prev = node;
	if (*a == NULL)
	{
		*a = node;
		return ;
	}
	curr = *a;
	while (curr->next && curr->next != *a)
		curr = curr->next;
	node->id = curr->id + 1;
	node->prev = curr;
	node->next = *a;
	curr->next = node;
	(*a)->prev = node;
}
