/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:25:57 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/28 12:45:24 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		set_first_min(t_stack *stack, t_pile *a)
{
	t_pile		*am;
	int			min;
	int			len;

	min = a->n;
	am = a;
	len = 0;
	while (am && len < stack->len_a)
	{
		if (am->n < min)
			min = am->n;
		if (am && am->next)
			am = am->next;
		len++;
	}
	return (min);
}

void			set_min_nmin(t_stack *stack, t_pile *a, int tab[2])
{
	t_pile		*am;
	int			nmin;
	int			min;
	int			len;

	(void)a;
	min = set_first_min(stack, stack->a);
	am = stack->a;
	nmin = 2147483647;
	len = 0;
	while (am && len < stack->len_a)
	{
		if (am->n > min && am->n < nmin)
			nmin = am->n;
		if (am && am->next)
			am = am->next;
		len++;
	}
	tab[0] = min;
	tab[1] = nmin;
}

static int		half_sort(t_stack *stack, t_pile *a)
{
	t_pile	*tmp;

	tmp = NULL;
	while (a && a != tmp && (tmp = stack->a))
	{
		if (a->next != stack->a && a->next->n < a->n)
			return (0);
		a = a->next;
	}
	return (1);
}

void			pre_sort_five(t_stack *stack, t_pile *a, t_pile *b, int tab[2])
{
	int		pb;

	pb = 0;
	while (pb < 2)
	{
		if (a->n == tab[0] || a->n == tab[1])
		{
			exec_instruction(stack, "pb");
			pb++;
		}
		else if (a->next->n == tab[0] || a->next->n == tab[1])
		{
			exec_multiple(stack, "sa", "pb");
			pb++;
		}
		else if (a->prev->n == tab[0] || a->prev->n == tab[1])
		{
			exec_multiple(stack, "rra", "pb");
			pb++;
		}
		else
			exec_instruction(stack, "rra");
		b = stack->b;
		a = stack->a;
	}
}

void			lst_sort_five(t_stack *stack)
{
	int		tab[2];

	set_min_nmin(stack, stack->a, tab);
	pre_sort_five(stack, stack->a, stack->b, tab);
	if (!half_sort(stack, stack->a))
		lst_sort_three(stack, stack->a);
	if (stack->b->n < stack->b->next->n)
		exec_instruction(stack, "sb");
	exec_multiple(stack, "pa", "pa");
}
