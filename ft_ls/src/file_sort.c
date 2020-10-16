/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:12:32 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 21:24:54 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			file_cmp(t_files **a, t_files **b, t_fg *g_fg)
{
	int			cmp;

	cmp = ft_strcmp((*a)->name, (*b)->name);
	if (*g_fg & MODIFICATION_DATE_SORT)
	{
		cmp = sort_time((*a)->name, (*b)->name, &(*a)->cmptime, &(*b)->cmptime);
	}
	return (cmp);
}

static void			sorted_insert(t_files **head, t_files *new, t_fg *g_fg)
{
	t_files		*curr;

	if (*head == NULL)
		*head = new;
	else if (file_cmp(&(*head), &new, g_fg) > 0)
	{
		new->next = *head;
		new->next->prev = new;
		*head = new;
	}
	else
	{
		curr = *head;
		while (curr->next && file_cmp(&(curr->next), &new, g_fg) < 0)
			curr = curr->next;
		new->next = curr->next;
		if (curr->next != NULL)
			new->next->prev = new;
		curr->next = new;
		new->prev = curr;
	}
}

void				reverse_files(t_files **files)
{
	t_files		*curr;
	t_files		*temp;

	temp = NULL;
	curr = *files;
	while (curr)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if (temp)
		*files = temp->prev;
}

void				insert_sort(t_files **head, t_fg *g_fg)
{
	t_files		*sorted;
	t_files		*curr;
	t_files		*next;

	sorted = NULL;
	next = NULL;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		curr->next = NULL;
		curr->prev = curr->next;
		sorted_insert(&sorted, curr, g_fg);
		curr = next;
	}
	*head = sorted;
}
