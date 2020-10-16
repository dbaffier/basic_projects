/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:16:13 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/09 11:27:25 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_copyuntil(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = 0;
	count = 0;
	while (src[i])
		if (src[i++] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}
