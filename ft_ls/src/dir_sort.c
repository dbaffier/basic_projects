/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:08:56 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 21:28:13 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct timespec			get_date(struct stat *f, t_fg *g_fg)
{
	struct timespec		cmp;

	cmp = f->st_mtimespec;
	if (*g_fg & MODIFICATION_DATE_SORT)
	{
		cmp = f->st_mtimespec;
		if (*g_fg & LAST_STATUS_CHANGE_SORT)
			cmp = f->st_ctimespec;
		else if (*g_fg & LAST_ACCESS_DATE_SORT)
			cmp = f->st_atimespec;
		else if (*g_fg & CREATION_DATE_SORT)
		{
			cmp = f->st_birthtimespec;
		}
	}
	return (cmp);
}

int						sort_time(char *a, char *b,
		struct timespec *aa, struct timespec *bb)
{
	long	diff;
	long	ndiff;

	diff = bb->tv_sec - aa->tv_sec;
	if (!diff)
	{
		ndiff = bb->tv_nsec - aa->tv_nsec;
		if (!ndiff)
			return (ft_strcmp(a, b));
		return (ndiff);
	}
	return (diff);
}

void					reverse_dirs(t_dirs **dirs)
{
	t_dirs		*curr;
	t_dirs		*temp;

	temp = NULL;
	curr = *dirs;
	while (curr)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if (temp)
		*dirs = temp->prev;
}
