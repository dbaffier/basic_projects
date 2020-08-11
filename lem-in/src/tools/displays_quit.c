/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 06:03:38 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 00:21:56 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_lst(t_room *room)
{
	if (room)
	{
		free(room->name);
		free_lst(room->next);
		free(room);
	}
}

void			print_free(t_path *path, char *line)
{
	free_lst(path->lst_room);
	if (line)
		free(line);
	ft_dprintf(2, "ERROR\n");
	exit(42);
}

int				exit_error_main(void)
{
	ft_dprintf(2, "ERROR\n");
	return (0);
}
