/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:09:20 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 10:57:50 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *s)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			count += 1;
		else if (s[i] <= 0x7FF)
			count += 2;
		else if (s[i] <= 0xFFFF)
			count += 3;
		else
			count += 4;
		i++;
	}
	return (count);
}
