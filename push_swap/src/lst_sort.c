/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 03:42:17 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/27 13:41:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_left(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack->len_a > 2)
	{
		i = current_b_min_index(stack->a, stack->len_a);
		if (i == 0)
			exec_instruction(stack, "pb");
		else if (i <= stack->len_a / 2)
			exec_instruction(stack, "ra");
		else if (i > stack->len_a / 2)
			exec_instruction(stack, "rra");
	}
}

static void		small_first(t_stack *stack)
{
	int		min;

	min = current_b_min_index(stack->a, stack->len_a);
	if (min <= stack->len_a / 2)
		while (min--)
			exec_instruction(stack, "ra");
	else
		while ((stack->len_a - min) > 0)
		{
			exec_instruction(stack, "rra");
			min++;
		}
}

static void		push_back_b(t_stack *stack)
{
	int		n;

	n = 0;
	while (stack->len_b)
	{
		stack->path = 0x0;
		n = find_a_places(stack, stack->len_a, stack->b);
		while (n > 0)
		{
			if (stack->path & N_RA)
				exec_instruction(stack, "ra");
			else
				exec_instruction(stack, "rra");
			n--;
		}
		exec_instruction(stack, "pa");
	}
	small_first(stack);
}

void			lst_sort(t_stack *stack)
{
	int		len;

	len = stack->len_a > 200 ? 50 : 2;
	while (stack->len_b != 2)
		exec_instruction(stack, "pb");
	while (stack->len_a > len)
	{
		evaluate(stack, stack->a);
		apply_path(stack);
		exec_instruction(stack, "pb");
	}
	push_left(stack);
	push_back_b(stack);
}
