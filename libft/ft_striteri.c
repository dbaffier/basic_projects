/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:57:26 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/06 18:06:58 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			l;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	l = ft_strlen(s);
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
