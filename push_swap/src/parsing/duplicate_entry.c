/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 03:30:17 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/19 03:03:36 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_each(t_pile *head, t_stack *stack)
{
	t_pile *current;

	current = head;
	head = head->next;
	while (head != current)
	{
		if (head->n == current->n)
			print_error(stack);
		head = head->next;
	}
}

int				duplicate_entry(t_pile *head, t_stack *stack)
{
	t_pile *end;

	if (!head)
		return (0);
	end = head->prev;
	while (head != end)
	{
		check_each(head, stack);
		head = head->next;
	}
	return (1);
}
