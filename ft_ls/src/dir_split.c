/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:19:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 20:47:20 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			dir_cmp(t_dirs **a, t_dirs **b, t_fg *g_fg)
{
	int			cmp;

	cmp = ft_strcmp((*a)->path, (*b)->path);
	if (*g_fg & MODIFICATION_DATE_SORT)
	{
		cmp = sort_time((*a)->path, (*b)->path, &(*a)->cmptime, &(*b)->cmptime);
	}
	return (cmp);
}

static t_dirs		*split_dirs(t_dirs *head)
{
	t_dirs	*fast;
	t_dirs	*slow;
	t_dirs	*tmp;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	tmp = slow->next;
	slow->next = NULL;
	return (tmp);
}

static t_dirs		*merge_s_dirs(t_dirs *a, t_dirs *b, t_fg *g_fg)
{
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (dir_cmp(&a, &b, g_fg) < 0)
	{
		a->next = merge_s_dirs(a->next, b, g_fg);
		a->next->prev = a;
		a->prev = NULL;
		return (a);
	}
	else
	{
		b->next = merge_s_dirs(a, b->next, g_fg);
		b->next->prev = b;
		b->prev = NULL;
		return (b);
	}
}

t_dirs				*dirs_sort(t_dirs *dirs, t_fg *g_fg)
{
	t_dirs		*second;

	if (!dirs || !dirs->next)
		return (dirs);
	second = split_dirs(dirs);
	dirs = dirs_sort(dirs, g_fg);
	second = dirs_sort(second, g_fg);
	return (merge_s_dirs(dirs, second, g_fg));
}
