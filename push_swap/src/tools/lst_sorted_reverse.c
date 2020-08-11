/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorted_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 03:34:06 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/23 19:16:09 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lst_sorted_reverse(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*a;

	if (stack->b)
		return (0);
	a = stack->a;
	while (a && a != tmp && (tmp = stack->a))
	{
		if (a->next != stack->a && a->next->n > a->n)
			return (0);
		a = a->next;
	}
	return (1);
}
