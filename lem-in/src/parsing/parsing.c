/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 05:28:02 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 22:05:23 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_input(t_path *pf)
{
	int			ret;
	char		*line;

	check_ant(pf);
	while (get_next_line(0, &line) > 0)
	{
		if ((ret = init_parsing(pf, line)) < 0)
		{
			free(line);
			return (ret);
		}
		free(line);
	}
	if (!pf->start || !pf->end)
		print_free(pf, NULL);
	return (1);
}
