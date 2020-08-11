/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:33:22 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 11:57:24 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_pile(t_pile *head, int len)
{
	t_pile	*tmp;

	if (head)
	{
		while (len--)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}

void		print_error(t_stack *stack)
{
	if (stack->a)
		free_pile(stack->a, stack->len_a);
	if (stack->b)
		free_pile(stack->b, stack->len_b);
	ft_dprintf(2, "Error\n");
	exit(42);
}

void		print_flag_err(t_stack *stack, char c)
{
	if (stack->a)
		free_pile(stack->a, stack->len_a);
	if (stack->b)
		free_pile(stack->b, stack->len_b);
	ft_dprintf(2, "./push_swap illegal option -- %c\n", c);
	ft_dprintf(2, "usage : ./push_swap [-vcfrqsn]\n");
	exit(1);
}

void		print_usage(char *str)
{
	ft_dprintf(2, "usage : %s ARG\n", str);
	exit(42);
}

void		print_free_line(t_stack *stack, char *line)
{
	if (line)
		free(line);
	print_error(stack);
}
