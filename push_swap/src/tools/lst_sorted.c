/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:46:55 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 21:06:48 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lst_sorted(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*a;

	if (stack->b)
		return (0);
	if (stack->opts & OPT_R)
		return (lst_sorted_reverse(stack));
	a = stack->a;
	tmp = NULL;
	while (a && a != tmp && (tmp = stack->a))
	{
		if (a->next != stack->a && a->next->n < a->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int			lst_sorted_give(t_stack *stack, t_pile *give, int len)
{
	t_pile	*tmp;

	(void)stack;
	tmp = give;
	while (len--)
	{
		if (give->next != tmp && give->n > give->next->n)
			return (0);
		give = give->next;
	}
	return (1);
}
