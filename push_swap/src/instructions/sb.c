/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 03:09:24 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/23 18:50:48 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		list_of_2(t_stack *stack, t_pile *b)
{
	t_pile		*tmp;

	if (b->next->next == b)
	{
		tmp = b;
		b = b->next;
		b->next = tmp;
		stack->b = b;
		return (1);
	}
	return (0);
}

void			sb(t_stack *stack, t_pile *a, t_pile *b)
{
	t_pile *tmp2;
	t_pile *tmp3;

	(void)a;
	if (!b || (b && b->next == NULL))
		return ;
	if (!list_of_2(stack, b))
	{
		tmp2 = b->next;
		tmp3 = b->next->next;
		b->prev->next = b->next;
		b->next->next->prev = b;
		b->next->prev = b->prev;
		b->next->next = b;
		b->next = tmp3;
		b->prev = tmp2;
		stack->b = tmp2;
	}
}
