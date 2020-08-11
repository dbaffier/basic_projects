/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:45:01 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/24 23:17:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		pb_b_null(t_stack *stack, t_pile **a)
{
	(*a)->prev = *a;
	(*a)->next = NULL;
	stack->b = *a;
	stack->len_b = stack->len_b + 1;
	stack->len_a = stack->len_a - 1;
}

void			pb(t_stack *stack, t_pile *a, t_pile *b)
{
	t_pile		*tmp;

	if (!a)
		return ;
	tmp = a;
	if (a->next)
		a->next->prev = a->prev;
	a->prev->next = a->next;
	stack->a = stack->a && stack->a == stack->a->next ? NULL : a->next;
	if (stack->a && stack->a == stack->a->next)
		stack->a->next = NULL;
	if (b == NULL)
	{
		pb_b_null(stack, &a);
		return ;
	}
	tmp->next = b;
	tmp->prev = b->prev;
	b->prev->next = tmp;
	b->prev = tmp;
	stack->b = tmp;
	stack->len_b = stack->len_b + 1;
	stack->len_a = stack->len_a - 1;
}
