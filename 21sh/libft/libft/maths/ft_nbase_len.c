/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:37:17 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 11:47:10 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nbase_lenbis(uintmax_t n, int len)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / len;
		i++;
	}
	return (i);
}

unsigned int			ft_nbase_len(uintmax_t n, char *base)
{
	return (ft_nbase_lenbis(n, ft_strlen(base)));
}
