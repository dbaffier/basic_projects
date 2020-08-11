/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:51:18 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/24 19:53:39 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		eval_move_a_b(t_stack *stack, int index,
		t_pile *element, int *tab)
{
	stack->path = 0x0;
	tab[0] = eval_moves(stack, stack->len_a, index, 65);
	tab[1] = find_b_moves(stack, stack->len_b, element);
	tab[2] = eval_dupplicate(stack, tab);
	return (tab[0] + tab[1] + tab[2] + 1);
}

void			apply_path(t_stack *stack)
{
	while (stack->dupp--)
	{
		if (stack->path & N_RR)
			exec_instruction(stack, "rr");
		else
			exec_instruction(stack, "rrr");
	}
	while (stack->pos_a--)
	{
		if (stack->path & N_RA)
			exec_instruction(stack, "ra");
		else
			exec_instruction(stack, "rra");
	}
	while (stack->pos_b--)
	{
		if (stack->path & N_RB)
			exec_instruction(stack, "rb");
		else
			exec_instruction(stack, "rrb");
	}
}

static int		assign_path(t_stack *stack, int *tab)
{
	stack->pos_a = tab[0];
	stack->pos_b = tab[1];
	stack->dupp = tab[2];
	return (stack->path);
}

int				evaluate(t_stack *stack, t_pile *a)
{
	int		i;
	int		tab[3];
	int		count;
	int		r_count;
	int		flg;

	i = -1;
	r_count = 0;
	while (++i < stack->len_a)
	{
		count = eval_move_a_b(stack, i, a, tab);
		if (i == 0)
		{
			r_count = count;
			flg = assign_path(stack, tab);
		}
		else if (r_count > count)
		{
			r_count = count;
			flg = assign_path(stack, tab);
		}
		a = a->next;
	}
	stack->path = flg;
	return (count);
}
