/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:19:03 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/27 13:41:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				eval_moves(t_stack *stack, int len, int index, int key)
{
	if (index > len / 2)
	{
		stack->path |= key == 65 ? N_RRA : N_RRB;
		if (len > 2)
			index = len - index;
	}
	else
		stack->path |= key == 65 ? N_RA : N_RB;
	return (index);
}

static int		brut_force(t_stack *stack, t_pile *element, int len, int key)
{
	int			i;
	int			pos;
	t_pile		*a;

	i = -1;
	a = key == 65 ? stack->a : stack->b;
	pos = 0;
	if (key == 65)
		while (++i < len)
		{
			if (element->n > a->n && ((i + 1 < len && element->n < a->next->n)
						|| (i + 1 == len && element->n < stack->a->n)))
				return (i + 1);
			a = a->next;
		}
	else
		while (++i < len)
		{
			if (element->n < a->n && ((i + 1 < len && element->n > a->next->n)
						|| (i + 1 == len && element->n > stack->a->n)))
				return (i + 1);
			a = a->next;
		}
	return (pos);
}

int				find_b_moves(t_stack *stack, int len, t_pile *element)
{
	int		i;
	int		pos;
	t_pile	*b;

	i = -1;
	b = stack->b;
	pos = 0;
	if (len == 2 && element->n > stack->b->n && element->n < stack->b->prev->n)
		pos = 0;
	else if (len == 2 && element->n < stack->b->n
			&& element->n > stack->b->prev->n)
		pos = 1;
	else if (element->n > current_b_max(stack->b, stack->len_b)
			|| element->n < current_b_min(stack->b, stack->len_b))
		pos = current_b_index(stack->b, stack->len_b);
	else
		pos = brut_force(stack, element, len, 66);
	return (eval_moves(stack, len, pos, 66));
}

int				find_a_places(t_stack *stack, int len, t_pile *element)
{
	int			i;
	int			pos;
	t_pile		*a;

	i = -1;
	pos = 0;
	a = stack->a;
	if (len == 2 && element->n > stack->a->n && element->n < stack->a->prev->n)
		pos = 1;
	else if (len == 2 && element->n < stack->a->n
			&& element->n > stack->a->prev->n)
		pos = 0;
	else if (element->n > current_b_max(stack->a, stack->len_a)
			|| element->n < current_b_min(stack->a, stack->len_a))
		pos = current_b_min_index(stack->a, stack->len_a);
	else
		pos = brut_force(stack, element, len, 65);
	return (eval_moves(stack, len, pos, 65));
}

int				eval_dupplicate(t_stack *stack, int *tab)
{
	int		both;

	both = 0;
	if ((stack->path & N_RA && stack->path & N_RB)
			|| (stack->path & N_RRA && stack->path & N_RRB))
	{
		both = (tab[0] > tab[1]) ? tab[1] : tab[0];
		if (both < 0)
			return (0);
		if (both)
		{
			tab[0] = tab[0] - both;
			tab[1] = tab[1] - both;
			stack->path |= (stack->path & N_RA && stack->path & N_RB)
				? N_RR : N_RRR;
		}
	}
	return (both);
}
