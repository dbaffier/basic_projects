/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expand2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:03:00 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 11:34:51 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"
#include "expansions.h"

void	get_prefix(char *str, t_tilde *tilde)
{
	int		i;
	int		state;

	i = 0;
	if (str[i] == 0)
		return ;
	while (str[i] && str[i] != '/')
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			tilde->flags |= TILDE_QUOTED;
			return ;
			state = str[i++];
			while (str[i] && str[i] != state)
				i++;
		}
		i++;
	}
	if (i == 0)
		return ;
	if (!(tilde->prefix = malloc(sizeof(char) * i + 1)))
		return ;
	ft_strncpy(tilde->prefix, str, i);
	tilde->prefix[i] = 0;
}
