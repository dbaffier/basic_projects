/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:56:40 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/11 02:06:53 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			init_parsing(t_path *pf, char *line)
{
	if (line[0] == 'L')
		print_free(pf, line);
	if (line[0] == '#')
		return (parse_rule(pf, line));
	if ((ft_count_occ(line, ' ') == 2) && pf->p_room == 0)
	{
		if (ft_strchr(line, '-'))
			return (-1);
		return (parse_room(pf, line, NULL, 0));
	}
	if (ft_count_occ(line, '-') == 1)
	{
		if (ft_strchr(line, ' '))
			return (-1);
		return (parse_link(pf, line));
	}
	print_free(pf, line);
	return (1);
}
