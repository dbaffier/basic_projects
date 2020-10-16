/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 08:32:24 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/14 09:02:12 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startstr(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	return (1);
}
