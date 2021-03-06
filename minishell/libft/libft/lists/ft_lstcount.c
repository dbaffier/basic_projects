/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:22:03 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/09 11:22:37 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcount(t_list *alst)
{
	size_t		i;

	i = 0;
	while (alst)
	{
		i++;
		alst = alst->next;
	}
	return (i);
}
