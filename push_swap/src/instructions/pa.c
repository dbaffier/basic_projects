/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:52:37 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/24 23:17:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_a_null(t_stack *stack, t_pile **b)
{
	(*b)->prev = *b;
	(*b)->next = NULL;
	stack->a = *b;
	stack->len_a = stack->len_a + 1;
	stack->len_b = stack->len_b == 0 ? stack->len_b : stack->len_b - 1;
}

void		pa(t_stack *stack, t_pile *a, t_pile *b)
{
	t_pile *tmp;

	if (!b)
		return ;
	if (b->next)
		b->next->prev = b->prev;
	b->prev->next = b->next;
	stack->b = stack->b == stack->b->next ? NULL : b->next;
	if (stack->b && stack->b == stack->b->next)
		stack->b->next = NULL;
	if (a == NULL)
	{
		pa_a_null(stack, &b);
		return ;
	}
	tmp = b;
	tmp->next = a;
	tmp->prev = a->prev;
	a->prev->next = tmp;
	a->prev = tmp;
	stack->a = tmp;
	stack->len_a = stack->len_a + 1;
	stack->len_b = stack->len_b == 0 ? stack->len_b : stack->len_b - 1;
}
