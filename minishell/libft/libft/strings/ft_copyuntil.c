/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:16:13 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/16 01:42:04 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_copyuntil(char **dst, char *src, char c)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			break ;
		i++;
	}
	if (!(*dst = ft_strnew(i)))
		return (0);
	ft_strncpy(*dst, src, i);
	return (i);
}
