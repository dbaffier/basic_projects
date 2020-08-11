/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 05:26:30 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/24 23:10:09 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_two(t_stack *stack, t_pile *a, t_pile *b)
{
	if (stack->a->n > a->next->n)
		exec_instruction(stack, "sa");
	if (b && stack->b->n < b->next->n)
		exec_instruction(stack, "sb");
}

static void		sort_four(t_stack *stack, t_pile *a, t_pile *b)
{
	int			tab[2];

	set_min_nmin(stack, a, tab);
	pre_sort_five(stack, a, b, tab);
	sort_two(stack, stack->a, stack->b);
	exec_instruction(stack, "pa");
	exec_instruction(stack, "pa");
}

static void		pivot_smallest(t_stack *stack, t_pile *a)
{
	if (a->prev->n > a->next->n)
		exec_instruction(stack, "ra");
	else
		exec_instruction(stack, "sa");
}

static void		pivot_biggest(t_stack *stack, t_pile *a)
{
	if (a->prev->n > a->next->n)
		exec_instruction(stack, "rra");
	else
	{
		exec_instruction(stack, "sa");
		exec_instruction(stack, "ra");
	}
}

void			lst_sort_three(t_stack *stack, t_pile *a)
{
	if (lst_sorted(stack))
		return ;
	if (stack->len_a == 4)
	{
		sort_four(stack, stack->a, stack->b);
		return ;
	}
	if (stack->len_a == 2)
	{
		sort_two(stack, stack->a, stack->b);
		return ;
	}
	a = a->next;
	if (a->prev->n > a->n && a->next->n > a->n)
		pivot_smallest(stack, a);
	else if (a->prev->n < a->n && a->next->n < a->n)
		pivot_biggest(stack, a);
	else
	{
		exec_instruction(stack, "ra");
		exec_instruction(stack, "sa");
	}
}
