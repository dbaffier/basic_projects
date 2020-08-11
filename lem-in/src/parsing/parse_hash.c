/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 06:07:00 by mmonier           #+#    #+#             */
/*   Updated: 2019/07/10 23:16:13 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_rule(t_path *pf, char *line)
{
	t_rule		tab[] = {END, START};
	char		*str;
	size_t		i;

	i = 0;
	if (line[0] == '#' && line[1] != '#')
		return (1);
	while (i < sizeof(tab) / sizeof(*tab))
	{
		if (ft_strcmp(tab[i].rule, line) == 0)
		{
			while (get_next_line(0, &str) > 0)
			{
				if (str[0] != '#')
					break ;
				free(str);
			}
			if (parse_room(pf, str, fill_name(str, ' '), tab[i].mask) == 1)
				;
			else
				return (-1);
			return (1);
		}
		i++;
	}
	print_free(pf, line);
	return (-1);
}
