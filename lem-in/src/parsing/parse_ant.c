/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:31:25 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 00:24:13 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		bound_checker(t_path *pf, char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) == 10)
	{
		while (line[i])
		{
			if (line[i] > STR_MAX[i])
				print_free(pf, line);
			i++;
		}
	}
}

int			check_ant(t_path *pf)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		print_free(pf, line);
	if ((line && line[0] == '\0') || (ft_strlen(line) == 1 && line[0] == 48))
		print_free(pf, line);
	if (ft_isnumber(line) == 0)
		print_free(pf, line);
	bound_checker(pf, line);
	pf->ant_n = ft_atoi(line);
	free(line);
	return (1);
}
