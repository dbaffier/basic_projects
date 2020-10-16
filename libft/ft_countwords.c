/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:18:33 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/09 11:19:39 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countwords(char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
			count++;
		if (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}
