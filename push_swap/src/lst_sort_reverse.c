/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 03:41:47 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/22 14:55:32 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lst_sort_reverse(t_stack *stack)
{
	int		i;
	int		len;

	i = 0;
	len = stack->len_a;
	while (i < len)
	{
		exec_instruction(stack, "pb");
		i++;
	}
	i = 0;
	while (i < len)
	{
		exec_instruction(stack, "rrb");
		exec_instruction(stack, "pa");
		i++;
	}
}
