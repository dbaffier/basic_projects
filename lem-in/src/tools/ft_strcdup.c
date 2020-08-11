/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 22:13:00 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/30 18:49:00 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_strclen(char *line, char c)
{
	int i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	return (i);
}

char			*fill_name(char *line, char c)
{
	int i;
	int len;
	char *str;

	i = 0;
	len = ft_strclen(line, c);
	if (!(str = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (line[i] && line[i] != c)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
