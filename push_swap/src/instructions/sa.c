/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:56:07 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/23 18:50:21 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		list_of_2(t_stack *stack, t_pile *a)
{
	t_pile		*tmp;

	if (a && a->next && a->next->next == a)
	{
		tmp = a;
		a = a->next;
		a->next = tmp;
		stack->a = a;
		return (1);
	}
	return (0);
}

void			sa(t_stack *stack, t_pile *a, t_pile *b)
{
	t_pile *tmp2;
	t_pile *tmp3;

	(void)b;
	if (!a || (a && a->next == NULL))
		return ;
	if (!list_of_2(stack, a))
	{
		tmp2 = a->next;
		tmp3 = a->next->next;
		a->prev->next = a->next;
		a->next->next->prev = a;
		a->next->prev = a->prev;
		a->next->next = a;
		a->next = tmp3;
		a->prev = tmp2;
		stack->a = tmp2;
	}
}
