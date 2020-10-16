/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 05:26:15 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 21:23:30 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline time_t		get_date_t(t_files *file, t_fg *g_fg)
{
	if (*g_fg & LAST_STATUS_CHANGE_SORT)
		return (file->f.st_ctime);
	else if (*g_fg & LAST_ACCESS_DATE_SORT)
		return (file->f.st_atime);
	else if (*g_fg & CREATION_DATE_SORT)
		return (file->f.st_birthtime);
	return (file->f.st_mtime);
}

static inline int			ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}

void						ls_lm_time(t_files *file, t_fg *g_fg)
{
	char	*tmp;
	time_t	currtime;
	time_t	var_time;

	var_time = get_date_t(file, g_fg);
	currtime = time(0);
	tmp = ctime(&var_time);
	if (ft_abs(currtime - var_time) > 15770000)
	{
		if (tmp[20] == ' ')
			ft_printf("%3.3s %2.2s  %5.5s ", &tmp[4], &tmp[8], &tmp[24]);
		else
			ft_printf("%3.3s %2.2s  %4.4s ", &tmp[4], &tmp[8], &tmp[20]);
	}
	else
	{
		ft_printf("%3.3s %2.2s %5.5s ", &tmp[4], &tmp[8], &tmp[11]);
	}
}
