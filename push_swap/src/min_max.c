/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:20:07 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/23 19:25:55 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				current_b_max(t_pile *b, int len)
{
	int		i;
	int		max;

	max = b->n;
	i = 0;
	if (len == 0)
		return (-1);
	while (i < len)
	{
		if (b->n > max)
			max = b->n;
		b = b->next;
		i++;
	}
	return (max);
}

int				current_b_min(t_pile *b, int len)
{
	int		i;
	int		max;

	max = b->n;
	i = 0;
	if (len == 0)
		return (-1);
	while (i < len)
	{
		if (b->n < max)
			max = b->n;
		i++;
		b = b->next;
	}
	return (max);
}

int				current_b_index(t_pile *b, int len)
{
	int		i;
	int		index;
	int		max;
	t_pile	*s;

	max = b->n;
	i = 0;
	if (len == 0)
		return (-1);
	index = 0;
	s = b;
	while (i < len)
	{
		if (b->n > max)
		{
			max = b->n;
			index = i;
		}
		b = b->next;
		i++;
	}
	return (index);
}

int				current_b_min_index(t_pile *b, int len)
{
	int		i;
	int		index;
	int		max;

	max = b->n;
	i = 0;
	if (len == 0)
		return (-1);
	index = 0;
	while (i < len)
	{
		if (b->n < max)
		{
			max = b->n;
			index = i;
		}
		b = b->next;
		i++;
	}
	return (index);
}
